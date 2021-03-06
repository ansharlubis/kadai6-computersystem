typedef enum {
  false,
  true
} Signal;

typedef struct {
  Signal s;
} Path;

typedef struct {
  int num;
  Path *p;
} Bus;

typedef struct {
  Path *in1;
  Path *in2;
  Path *out1;
} ANDGate;

typedef struct {
  int num;
  Path **ins;
  Path *out1;
} ANDGateN;

typedef struct {
  int num;
  Path **ins;
  Path *out1;
} ORGateN;

typedef struct {
  Path *in1;
  Path *in2;
  Path *out1;
} ORGate;

typedef struct {
  Path *in1;
  Path *out1;
} NOTGate;

typedef struct {
  ANDGate *agate1;
  NOTGate *ngate1;
} NANDCircuit;

typedef struct {
  NOTGate *ngate1;
  NOTGate *ngate2;
  ANDGate *agate1;
  ANDGate *agate2;
  ORGate *ogate1;
} XORCircuit;

typedef struct {
  XORCircuit *xorc1;
  XORCircuit *xorc2;
  ANDGate *agate1;
  ANDGate *agate2;
  ORGate *ogate1;
} FA;

typedef struct {
  FA *f;
} RCA;

typedef struct {
  ANDGate *agate1;
  ORGate *ogate1;
  FA *f1;
} PFA;

typedef struct {
  ANDGate *agates;
  ORGate *ogates;
} CLU;

typedef struct {
  PFA *pfa;
  CLU *clu;
  ANDGateN *agaten;
  ORGateN *ogaten;
} CLA4;

void path_set_signal(Path *p, Signal s);
Signal path_get_signal(Path *p);
void path_init(Path *p);

void bus_init(Bus *b, int n);
void bus_set_value(Bus *b, int val);
int bus_get_value(Bus *b);
Path* bus_get_path(Bus *b, int i);
void bus_release(Bus *b);

void andgate_init(ANDGate *agate, Path *in1, Path *in2, Path *out1);
void andgate_run(ANDGate *agate);
void andgate_driver(Signal a, Signal b);

void andgaten_init(ANDGateN *agaten, Path **ins, Path *out1, int num);
void andgaten_run(ANDGateN *agaten);

void orgate_init(ORGate *ogate, Path *in1, Path *in2, Path *out1);
void orgate_run(ORGate *ogate);
void orgate_driver(Signal a, Signal b);

void orgaten_init(ORGateN *ogaten, Path **ins, Path *out1, int num);
void orgaten_run(ORGateN *ogaten);

void notgate_init(NOTGate *ngate, Path *in1, Path *out1);
void notgate_run(NOTGate *ngate);
void notgate_driver(Signal a);

void nandcircuit_init(NANDCircuit *nandc, Path *in1, Path *in2, Path *out1);
void nandcircuit_run(NANDCircuit *nandc);
void nandcircuit_release(NANDCircuit *nandc);
Path* nandcircuit_get_out_path(NANDCircuit *nandc);
void nandcircuit_driver(Signal a, Signal b);

void xorcircuit_init(XORCircuit *xorc, Path *in1, Path *in2, Path *out1);
void xorcircuit_run(XORCircuit *xorc);
void xorcircuit_release(XORCircuit *xorc);
Path* xorcircuit_get_out_path(XORCircuit *xorc);
void xorcircuit_driver(Signal a, Signal b);

void fa_init(FA *f, Path *in1, Path *in2, Path *carryin, Path *out1, Path *carryout);
void fa_run(FA *f);
void fa_release(FA *f);
Path* fa_get_out_path(FA *f);
Path* fa_get_carry_out_path(FA *f);
void fa_driver(Signal a, Signal b, Signal carry_in);

void rca_init(RCA *r, Bus *a, Bus *b, Path *carryin, Bus *s, Path *carryout);
void rca_run(RCA *r);
void rca_release(RCA *r);
void rca_driver(int na, int nb);

void pfa_init(PFA *pfa, Path *a, Path *b, Path *carryin, Path *g, Path *p, Path *s);
void pfa_run(PFA *pfa);
void pfa_release(PFA *pfa);
void pfa_driver(Signal a, Signal b, Signal carry_in);

void clu_init(CLU *clu, Bus *g, Bus *p, Bus *c, Path *carryout);
void clu_run(CLU *clu);
void clu_release(CLU *clu);
void clu_driver(int ng, int np);

void cla4_init(CLA4 *cla4, Bus *a, Bus *b, Path *carryin, Bus *s, Path *carryout, Path *G, Path *P);
void cla4_run(CLA4 *cla4);
void cla4_release(CLA4 *cla4);
void cla4_driver(int na, int nb);

