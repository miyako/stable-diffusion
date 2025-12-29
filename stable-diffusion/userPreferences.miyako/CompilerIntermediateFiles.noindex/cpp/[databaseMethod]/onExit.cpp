extern Txt KONNX;
extern Txt Knew;
extern Txt Kterminate;
extern unsigned char D_db_3[];
void db_3( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_db_3);
	if (!ctx->doingAbort && c.f.fLine==0) {
		Obj lONNX;
		{
			Obj t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1710)) goto _0;
			Variant t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv(),KONNX.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t2;
			if (g->Call(ctx,(PCV[]){t2.cv(),t1.cv(),Knew.cv()},2,1498)) goto _0;
			Obj t3;
			if (!g->GetValue(ctx,(PCV[]){t3.cv(),t2.cv(),nullptr})) goto _0;
			lONNX=t3.get();
		}
		c.f.fLine=3;
		if (g->Call(ctx,(PCV[]){nullptr,lONNX.cv(),Kterminate.cv()},2,1500)) goto _0;
		g->Check(ctx);
_0:
_1:
;
	}

}
