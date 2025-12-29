extern Txt Kcheck;
extern Txt Knew;
extern Txt Ktcp;
extern unsigned char D_proc_MAIN[];
void proc_MAIN( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc_MAIN);
	if (!ctx->doingAbort && c.f.fLine==0) {
		Obj ltcp;
		{
			Long t0;
			t0=inNbExplicitParam;
			if (2!=t0.get()) goto _3;
		}
		{
			Txt t2;
			c.f.fLine=7;
			if (g->Call(ctx,(PCV[]){t2.cv()},0,684)) goto _0;
			g->Check(ctx);
			Obj t3;
			if (g->Call(ctx,(PCV[]){t3.cv()},0,1471)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,Long(1).cv(),t2.cv(),Parm<Obj>(inParams,1).cv(),Parm<Obj>(inParams,2).cv(),t3.cv()},5,1389)) goto _0;
		}
		asm volatile("");
		goto _2;
_3:
		{
			Long t4;
			t4=inNbExplicitParam;
			if (3!=t4.get()) goto _4;
		}
		{
			Obj t6;
			c.f.fLine=12;
			if (g->Call(ctx,(PCV[]){t6.cv()},0,1710)) goto _0;
			Variant t7;
			if (g->Call(ctx,(PCV[]){t7.cv(),t6.cv(),Ktcp.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t8;
			if (g->Call(ctx,(PCV[]){t8.cv(),t7.cv(),Ktcp.cv(),Long(56).cv()},3,1496)) goto _0;
			Variant t9;
			if (g->Call(ctx,(PCV[]){t9.cv(),t8.cv(),Knew.cv()},2,1498)) goto _0;
			Obj t10;
			if (!g->GetValue(ctx,(PCV[]){t10.cv(),t9.cv(),nullptr})) goto _0;
			ltcp=t10.get();
		}
		c.f.fLine=13;
		if (g->Call(ctx,(PCV[]){nullptr,ltcp.cv(),Kcheck.cv(),Parm<Obj>(inParams,1).cv(),Parm<Obj>(inParams,2).cv()},4,1500)) goto _0;
		g->Check(ctx);
		asm volatile("");
		goto _2;
_4:
_2:
_0:
_1:
;
	}

}
