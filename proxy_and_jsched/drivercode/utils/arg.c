////////////////////////////////////////////////////////////////
// simple argument parsing with documentation

// options can be typed as int, char, char*, bool, double, or handled by a special function
// positional parameters are always string and must be listed in order
// a special type Rest means all rest are returned as a pointer

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "util.h"
#include "arg.h"

#define false 0
#define true (!false)
typedef unsigned int bool;

static int verbose = 0;
static char* commandLine;
static const char* pname;

// order is based on how enums are defined in ArgType
static char* type2fmt[] = {
  "",
  "<int>",
  "<char>",
  "<string>",
  "<bool>",
  "<double>",
  "",
  "",
  "" };
  
static void usage(const char* pname, ArgParser* def);

static void
argdie(ArgParser* def, const char* fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    fprintf(stderr, "%s: Usage Error: ", pname);
    vfprintf(stderr, fmt, ap);
    va_end (ap);
    fprintf(stderr, "\n");
    usage(pname, def);
    exit(-1);
}


static const char*
arg2str(ArgOption* desc)
{
  static char buffer[128];
  char* p = buffer;
  char sep = (desc->kind == KindPositional) ? ':' : ' ';

  if (desc->kind == Help) {
    return "[-h]";
  }
  
  if ((desc->kind == KindPositional)&&(desc->required)) {
    *p++ = '<';
  } else if (!desc->required) {
    *p++ = '[';
  }

  switch(desc->type) {
  case Integer:
  case Character:
  case String:
  case Boolean:
  case Double:
    sprintf(p, "%s%c%s", desc->longarg, sep, type2fmt[desc->type]);
    p += strlen(p);
    break;
    
  case Function:
    sprintf(p, "%s%c%s", desc->longarg, sep, (*(argOptionParser)(desc->dest))(ArgGetDesc, NULL));
    p += strlen(p);
    break;
    
  case Help:
  case Toggle:
  case Set:
  case Increment:
    sprintf(p, "%s", desc->longarg);
    p += strlen(p);
    break;
    
  default:
    // new type that we didn't implement yet?
    fprintf(stderr, "%d\n", desc->type);
    assert(0);
  }
  if (desc->kind == KindRest) {
    strcpy(p, "...");
    p += strlen(p);
  }

  if ((desc->kind == KindPositional)&&(desc->required)) {
    *p++ = '>';
  } else if (!desc->required) {
    *p++ = ']';
  }
  *p = 0;
  return buffer;
}


static void 
usage(const char* pname, ArgParser* ap)
{
  fprintf(stderr, "%s: ", pname);
  // print out shorthand for arguments
  for (ArgParserNode* apn = ap->parsers; apn; apn=apn->next) {
    ArgOption* args = apn->parser->args;
    int i=0;
    while (args[i].kind != KindEnd) {
      fprintf(stderr, " %s", arg2str(args+i));
      i++;
    }
    fprintf(stderr, "\n%s\n", apn->parser->progdoc);
  }

  // Now print individual descriptions
  for (ArgParserNode* apn = ap->parsers; apn; apn=apn->next) {
    ArgOption* args = apn->parser->args;
    int i = 0;
    while (args[i].kind != KindEnd) {
      fprintf(stderr, "   %20s\t%s\t", arg2str(args+i), args[i].kind == KindHelp ? "Print this message" : args[i].desc);
      switch (args[i].type) {
      case Increment:
      case Integer:
	fprintf(stderr, "(default: %d)", *(int *)(args[i].dest));
	break;

      case Character:
	fprintf(stderr, "(default: %c)", *(char *)(args[i].dest));
	break;

      case String:
	fprintf(stderr, "(default: %s)", (char*)(args[i].dest));
	break;

      case Toggle:
      case Set:
      case Boolean:
	fprintf(stderr, "(default: %s)", *(int *)(args[i].dest) ? "true" : "false");
	break;

      case Double:
	fprintf(stderr, "(default: %lf)", *(double *)(args[i].dest));
	break;

      case Function:
	fprintf(stderr, "(default: %s)", (*(argOptionParser)(args[i].dest))(ArgGetDefault, NULL));
	break;

      case Help:
	break;
      }
      fprintf(stderr, "\n");
      i++;
    }
  }
}


void
makeCommandline(int argc, char** argv)
{
  int len = 2;
  for (int i=0; i<argc; i++) {
    len += (1 + strlen(argv[i]));
  }
  char* p = (char*)calloc(len, 1);
  len = 0;
  for (int i=0; i<argc; i++) {
    strcpy(p+len, argv[i]);
    len += strlen(argv[i]);
    p[len++] = ' ';
  }
  p[len-1] = 0;
  if (verbose) fprintf(stderr, "[%s]\n", p);
  commandLine = p;
}

// offset is 1 for option args (argv[0] points at option, argv[1] at start of data)
// offset is 0 for positional args (argv[0] points at actual argument)
static int
assignArg(ArgOption* desc, int argc, char** argv, ArgParser* ap, int offset)
{
  switch (desc->type) {
  case Increment:
    if (verbose) printf("incremement %s\n", desc->longarg);
    {
      int* p = (int*)desc->dest;
      (*p)++;
    }
    break;

  case Function:
    // call function with pointer to argv.  Expect # of argv consumed as return result.
    if (verbose) printf("calling function %s\n", desc->longarg);
    {
      argOptionParser aop = (argOptionParser)desc->dest;
      const char* ret = (*aop)(argc, argv);
      long int consumed = (long int)ret;
      return (int)consumed;
    }
    break;

  case String:
    if (verbose) printf("Saving %s to %s\n", argv[offset], desc->longarg);
    {
      char** p = (char**)desc->dest;
      *p = argv[offset];
      return 1;
    }
    break;

  case Set:
    if (verbose) printf("Setting %s to 1\n", desc->longarg);
    {
      int* p = (int*)desc->dest;
      *p = 1;
    }
    break;

  case Toggle:
    if (verbose) printf("toggeling %s\n", desc->longarg);
    {
      int* p = (int*)desc->dest;
      *p = !(*p);
    }
    break;

  case Double:
    if (verbose) printf("double -> [%s] = %lf\n", desc->longarg, atof(argv[offset]));
    {
      double* p = (double*)desc->dest;
      *p = atof(argv[offset]);
      return 1;
    }
    break;

  case Integer:
    if (verbose) printf("int -> [%s] = %d\n", desc->longarg, atoi(argv[offset]));
    {
      int* p = (int*)desc->dest;
      *p = atoi(argv[offset]);
      return 1;
    }
    break;

  case Help:
    usage(pname, ap);
    exit(-1);

  default:
    fprintf(stderr, "NIY: type\n");
    exit(-1);
  }
  return 0;
}

static const char*
kind2str(ArgKind k)
{
  switch (k) {
  case KindEnd: return "End";
  case KindHelp: return "Help";
  case KindPositional: return "Positional";
  case KindOption: return "Option";
  case KindRest: return "Rest";
  default:
    assert(0);
  }
  return "Unknown";
}


// return true if has help
bool
checkArgDef(ArgParser* ap, ArgDefs* def, bool main)
{
  // optional/help come before postional before rest
  int state = KindOption;
  ArgOption* desc = def->args;  
  int hashelp = false;
  
  for (int i=0; desc[i].kind != KindEnd; i++) {
    if (desc[i].kind > KindEnd)
      argdie(ap, "Bad kind - no KindEnd?");
    if (desc[i].kind != state) {
      if ((state == KindOption) && (desc[i].kind == KindHelp)&&(desc[i].longarg != NULL)) {
	hashelp = true;
	continue;
      }
      if (desc[i].kind < state)
	argdie(ap, "Bad order of arg defs: %s comes before last of %s", kind2str(state),  kind2str(desc[i].kind));
      state = desc[i].kind;
    }
    if (((state == KindPositional)||(state == KindRest))&&!main)
      argdie(ap, "positional args but not main");
  }
  return hashelp;
}

static void
checkArgParser(ArgParser* ap) {
  bool hashelp = false;
  for (ArgParserNode* apn = ap->parsers; apn; apn=apn->next) {
    hashelp |= checkArgDef(ap, apn->parser, apn->main);
  }
  if (!hashelp) 
    argdie(ap, "No help string");
}


int 
parseArgs(int argc, char** argv, ArgDefs* def)
{
  ArgParserNode n = { 1, def, NULL };
  ArgParser ap = { &n, def };
  return parseArguments(&ap, argc, argv);
}

////////////////////////////////////////////////////////////////
// multiple argument parsers

ArgParser* 
createArgumentParser(ArgDefs* def)
{
  ArgParser* ap = mycalloc(1, sizeof(ArgParser));
  ap->parsers = mycalloc(1, sizeof(ArgParserNode));
  ap->parsers->parser = def;
  ap->parsers->main = 1;
  ap->mainProg = def;
  return ap;
}

void 
freeArgumentParser(ArgParser* ap)
{
  ArgParserNode* next;
  ArgParserNode* p;
  for (p=ap->parsers; p; p=next) {
    next = p->next;
    free(p);
  }
  free(ap);
}

void 
addArgumentParser(ArgParser* ap, ArgDefs* def, int order)
{
  ArgParserNode* p = mycalloc(1, sizeof(ArgParserNode));
  p->parser = def;
  p->next = NULL;
  p->main = 0;
  
  if (order > 0) {
    ArgParserNode* nextp;
    for (nextp = ap->parsers; nextp->next; nextp = nextp->next);
    nextp->next = p;
  } else {
    p->next = ap->parsers;
    ap->parsers = p;
  }
}

int 
parseArguments(ArgParser* ap, int argc, char**argv)
{
  // get program name and commandline as a string
  pname = argv[0];
  makeCommandline(argc, argv);
  argv++; argc--;

  checkArgParser(ap);

  // process args
  if (verbose) fprintf(stderr, "Processing args for %s: %d\n", pname, argc);
  int maxarg = argc;
  int i;
  bool optionsPossible = true;
  for (i=0; (i<argc)&&optionsPossible; i++) {
    char* arg = argv[i];
    if (verbose) fprintf(stderr, "%d -> [%s]\n", i, arg);
    if (arg[0] == '-') {
      // Handle options
      bool ok = false;
      bool notfound = true;
      for (ArgParserNode* apn = ap->parsers; notfound && apn; apn=apn->next) {
	ArgOption* desc = apn->parser->args;  
	
	for (int j=0; notfound && (desc[j].kind != KindEnd); j++) {
	  if (strcmp(desc[j].longarg, arg) == 0) {
	    ok = true;
	    notfound = false;
	    // see if it is special
	    if (desc[j].type == EndOptions) {
	      optionsPossible = false;
	      break;
	    }
	    // process it
	    int consumed = assignArg(desc+j, argc-i, argv+i, ap, 1);
	    i += consumed;
	  }
	}
      }
      if (!ok) 
	argdie(ap, "Do not understand the flag [%s]\n", arg);
    } else {
      // No more options
      break;
    }
  }
  // ok, now we handle positional args, we handle them in the order they are declared
  // only the main parser can define positional args
  ArgOption* desc = NULL;
  for (ArgParserNode* apn = ap->parsers; apn; apn=apn->next) {
    if (apn->main) {
      desc = apn->parser->args;
      break;
    }
  }
  assert(desc != NULL);
  int baseArg = i;
  int baseDestOffset;
  for (baseDestOffset=0; desc[baseDestOffset].kind != KindEnd; baseDestOffset++) {
    if ((desc[baseDestOffset].kind == KindPositional)||(desc[baseDestOffset].kind == KindRest)) break;
  }
  // base is first positional arg we are passed, j is first descriptor for positional arg
  if (verbose) 
    fprintf(stderr, "start pos: j=%d %s kind=%d basearg=%d\n", baseDestOffset, desc[baseDestOffset].longarg, desc[baseDestOffset].type, baseArg);
  int j=0;			/* positional offset */
  while ( (desc[baseDestOffset+j].kind == KindPositional) && ((baseArg+j) < argc) ) {
    if (verbose) printf("%d: %s\n", j, baseArg+desc[baseDestOffset+j].longarg);
    int consumed = assignArg(desc+baseDestOffset+j, argc-(baseArg+j), argv+baseArg+j, ap, 0);
    j += consumed;
  }
  // check that we used all the arguments and don't have any extra
  if (desc[baseDestOffset+j].type == KindPositional)
    argdie(ap, "Expected more arguments, only given %d", j);
  else if ((desc[baseDestOffset+j].type == KindEnd)&&((baseArg+j) < argc)) {
    argdie(ap, "Too many arguments, given %d", j);
  }
  // see if we have a variable number of args at end
  if (desc[baseDestOffset+j].type == KindRest)
    argdie(ap, "Haven't implemented Rest args yets");

  // if user defined a post parsing function, call it - main prog called last
  for (ArgParserNode* apn = ap->parsers; apn; apn=apn->next) {
    if ((apn->main != 1) && (apn->parser->doneParsing != NULL)) {
      (*(apn->parser->doneParsing))();
    }
  }
  if (ap->mainProg->doneParsing) {
    (*(ap->mainProg->doneParsing))();
  }

  return 0;
}

void
freeCommandLine(void)
{
  free(commandLine);
}

