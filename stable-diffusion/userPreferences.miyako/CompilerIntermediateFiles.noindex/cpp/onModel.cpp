extern Txt Kcall;
extern Txt Kerror;
extern Txt Kevent;
extern Txt Kmodels;
extern Txt Knew;
extern Txt KonError;
extern Txt Kport;
extern Txt Kremove;
extern Txt Ksuccess;
extern Txt Kworkers;
extern Txt kEQAtmrqWhrQ;
extern unsigned char D_proc_ONMODEL[];
void proc_ONMODEL( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc_ONMODEL);
	if (!ctx->doingAbort && c.f.fLine==0) {
		Obj lworkers;
		Obj lerror;
		{
			Variant t0;
			c.f.fLine=3;
			if (g->GetMember(ctx,Parm<Obj>(inParams,1).cv(),Ksuccess.cv(),t0.cv())) goto _0;
			Bool t1;
			if (!g->GetValue(ctx,(PCV[]){t1.cv(),t0.cv(),nullptr})) goto _0;
			if (!(t1.get())) goto _2;
		}
		asm volatile("");
		goto _3;
_2:
		{
			Obj t2;
			c.f.fLine=8;
			if (g->Call(ctx,(PCV[]){t2.cv()},0,1710)) goto _0;
			Variant t3;
			if (g->Call(ctx,(PCV[]){t3.cv(),t2.cv(),Kevent.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t4;
			if (g->Call(ctx,(PCV[]){t4.cv(),t3.cv(),Kerror.cv(),Long(56).cv()},3,1496)) goto _0;
			Obj t5;
			if (g->Call(ctx,(PCV[]){t5.cv()},0,1470)) goto _0;
			Variant t6;
			if (g->Call(ctx,(PCV[]){t6.cv(),t5.cv(),Kmodels.cv()},2,1498)) goto _0;
			Variant t7;
			if (g->Call(ctx,(PCV[]){t7.cv(),t4.cv(),Knew.cv(),Long(2).cv(),kEQAtmrqWhrQ.cv(),t6.cv()},5,1498)) goto _0;
			Obj t8;
			if (!g->GetValue(ctx,(PCV[]){t8.cv(),t7.cv(),nullptr})) goto _0;
			lerror=t8.get();
		}
		{
			Variant t9;
			c.f.fLine=10;
			if (g->GetMember(ctx,Parm<Obj>(inParams,2).cv(),Kevent.cv(),t9.cv())) goto _0;
			Bool t10;
			if (g->OperationOnAny(ctx,7,t9.cv(),Value_null().cv(),t10.cv())) goto _0;
			Bool t11;
			t11=t10.get();
			if (!(t10.get())) goto _4;
			{
				{
					Variant t12;
					if (g->GetMember(ctx,Parm<Obj>(inParams,2).cv(),Kevent.cv(),t12.cv())) goto _0;
					Obj t13;
					if (g->Call(ctx,(PCV[]){t13.cv()},0,1710)) goto _0;
					Variant t14;
					if (g->Call(ctx,(PCV[]){t14.cv(),t13.cv(),Kevent.cv(),Long(56).cv()},3,1496)) goto _0;
					g->Check(ctx);
					Variant t15;
					if (g->Call(ctx,(PCV[]){t15.cv(),t14.cv(),Kevent.cv(),Long(56).cv()},3,1496)) goto _0;
					Obj t16;
					if (!g->GetValue(ctx,(PCV[]){t16.cv(),t15.cv(),nullptr})) goto _0;
					Obj t17;
					if (!g->GetValue(ctx,(PCV[]){t17.cv(),t12.cv(),nullptr})) goto _0;
					Bool t18;
					if (g->Call(ctx,(PCV[]){t18.cv(),t17.cv(),t16.cv()},2,1731)) goto _0;
					t11=t18.get();
				}
			}
_4:
			if (!(t11.get())) goto _5;
		}
		{
			Variant t19;
			c.f.fLine=11;
			if (g->GetMember(ctx,Parm<Obj>(inParams,2).cv(),Kevent.cv(),t19.cv())) goto _0;
			Variant t20;
			if (g->GetMember(ctx,t19.cv(),KonError.cv(),t20.cv())) goto _0;
			Obj t21;
			if (g->Call(ctx,(PCV[]){t21.cv()},0,1470)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t20.cv(),Kcall.cv(),t21.cv(),Parm<Obj>(inParams,2).cv(),lerror.cv()},5,1500)) goto _0;
			g->Check(ctx);
		}
_5:
		{
			Obj t22;
			c.f.fLine=15;
			if (g->Call(ctx,(PCV[]){t22.cv()},0,1710)) goto _0;
			Variant t23;
			if (g->Call(ctx,(PCV[]){t23.cv(),t22.cv(),Kworkers.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t24;
			if (g->Call(ctx,(PCV[]){t24.cv(),t23.cv(),Kworkers.cv(),Long(56).cv()},3,1496)) goto _0;
			Variant t25;
			if (g->Call(ctx,(PCV[]){t25.cv(),t24.cv(),Knew.cv()},2,1498)) goto _0;
			Obj t26;
			if (!g->GetValue(ctx,(PCV[]){t26.cv(),t25.cv(),nullptr})) goto _0;
			lworkers=t26.get();
		}
		{
			Variant t27;
			c.f.fLine=16;
			if (g->GetMember(ctx,Parm<Obj>(inParams,2).cv(),Kport.cv(),t27.cv())) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,lworkers.cv(),Kremove.cv(),t27.cv()},3,1500)) goto _0;
			g->Check(ctx);
		}
_3:
_0:
_1:
;
	}

}
