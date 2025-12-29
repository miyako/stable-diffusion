extern Txt K__Model;
extern Txt Kevent;
extern Txt Khuggingfaces;
extern Txt Knew;
extern Txt Koptions;
extern Txt Kport;
extern unsigned char D_proc_START[];
void proc_START( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc_START);
	if (!ctx->doingAbort && c.f.fLine==0) {
		Obj lmodel;
		{
			Obj t0;
			c.f.fLine=4;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1710)) goto _0;
			Variant t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv(),K__Model.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t2;
			if (g->GetMember(ctx,Parm<Obj>(inParams,1).cv(),Kport.cv(),t2.cv())) goto _0;
			Variant t3;
			if (g->GetMember(ctx,Parm<Obj>(inParams,1).cv(),Khuggingfaces.cv(),t3.cv())) goto _0;
			Variant t4;
			if (g->GetMember(ctx,Parm<Obj>(inParams,1).cv(),Koptions.cv(),t4.cv())) goto _0;
			Variant t5;
			if (g->GetMember(ctx,Parm<Obj>(inParams,1).cv(),Kevent.cv(),t5.cv())) goto _0;
			Variant t6;
			if (g->Call(ctx,(PCV[]){t6.cv(),t1.cv(),Knew.cv(),t2.cv(),t3.cv(),t4.cv(),Parm<Obj>(inParams,2).cv(),t5.cv()},7,1498)) goto _0;
			Obj t7;
			if (!g->GetValue(ctx,(PCV[]){t7.cv(),t6.cv(),nullptr})) goto _0;
			lmodel=t7.get();
		}
_0:
_1:
;
	}

}
