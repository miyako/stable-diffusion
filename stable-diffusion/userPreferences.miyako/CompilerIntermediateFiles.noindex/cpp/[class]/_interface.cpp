extern Txt KPID;
extern Txt KTCP_20port_20;
extern Txt K_2C;
extern Txt Kcall;
extern Txt Kerror;
extern Txt Kevent;
extern Txt Kjoin;
extern Txt Kname;
extern Txt Knew;
extern Txt KonError;
extern Txt Kport;
extern Txt Ksuccess;
extern Txt k6An0hIigItE;
extern unsigned char D_proc___interface_2E__onTCP[];
void proc___interface_2E__onTCP( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___interface_2E__onTCP);
	if (!ctx->doingAbort && c.f.fLine==0) {
		Variant lname;
		Obj lerror;
		Txt lstatuses;
		{
			Variant t0;
			c.f.fLine=2;
			if (g->GetMember(ctx,Parm<Obj>(inParams,1).cv(),Ksuccess.cv(),t0.cv())) goto _0;
			Bool t1;
			if (!g->GetValue(ctx,(PCV[]){t1.cv(),t0.cv(),nullptr})) goto _0;
			if (!(t1.get())) goto _2;
		}
		{
			Variant t2;
			c.f.fLine=4;
			if (g->GetMember(ctx,Parm<Obj>(inParams,2).cv(),Kname.cv(),t2.cv())) goto _0;
			if (!g->SetValue(ctx,(PCV[]){t2.cv(),lname.cv(),nullptr})) goto _0;
		}
		{
			Ref t3;
			t3.setLocalRef(ctx,Parm<Obj>(inParams,2).cv());
			c.f.fLine=5;
			if (g->Call(ctx,(PCV[]){nullptr,t3.cv(),Kname.cv()},2,1226)) goto _0;
			g->Check(ctx);
		}
		asm volatile("");
		goto _3;
_3:
		{
			Obj t6;
			c.f.fLine=7;
			if (g->Call(ctx,(PCV[]){t6.cv(),Long(0).cv(),(CV*)-1,nullptr,Long(8).cv(),Long(0).cv()},5,1597)) goto _0;
			g->Check(ctx);
			asm volatile("");
			goto _4;
_4:
			Obj t9;
			if (g->Call(ctx,(PCV[]){t9.cv(),Long(0).cv(),(CV*)-1,nullptr,Long(9).cv(),Long(0).cv()},5,1597)) goto _0;
			Variant t10;
			if (!g->GetValue(ctx,(PCV[]){t10.cv(),lname.cv(),nullptr})) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t10.cv(),t6.cv(),Parm<Obj>(inParams,2).cv(),t9.cv()},4,1389)) goto _0;
		}
		asm volatile("");
		goto _5;
_2:
		{
			Variant t11;
			c.f.fLine=12;
			if (g->GetMember(ctx,Parm<Obj>(inParams,1).cv(),Kport.cv(),t11.cv())) goto _0;
			Txt t12;
			if (g->Call(ctx,(PCV[]){t12.cv(),t11.cv()},1,10)) goto _0;
			Txt t13;
			g->AddString(KTCP_20port_20.get(),t12.get(),t13.get());
			Txt t14;
			g->AddString(t13.get(),k6An0hIigItE.get(),t14.get());
			Variant t15;
			if (g->GetMember(ctx,Parm<Obj>(inParams,1).cv(),KPID.cv(),t15.cv())) goto _0;
			Variant t16;
			if (g->Call(ctx,(PCV[]){t16.cv(),t15.cv(),Kjoin.cv(),K_2C.cv()},3,1498)) goto _0;
			g->Check(ctx);
			Variant t17;
			if (g->OperationOnAny(ctx,0,t14.cv(),t16.cv(),t17.cv())) goto _0;
			Txt t18;
			if (!g->GetValue(ctx,(PCV[]){t18.cv(),t17.cv(),nullptr})) goto _0;
			lstatuses=t18.get();
		}
		{
			Obj t19;
			c.f.fLine=14;
			if (g->Call(ctx,(PCV[]){t19.cv()},0,1710)) goto _0;
			Variant t20;
			if (g->Call(ctx,(PCV[]){t20.cv(),t19.cv(),Kevent.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t21;
			if (g->Call(ctx,(PCV[]){t21.cv(),t20.cv(),Kerror.cv(),Long(56).cv()},3,1496)) goto _0;
			Variant t22;
			if (g->Call(ctx,(PCV[]){t22.cv(),t21.cv(),Knew.cv(),Long(1).cv(),lstatuses.cv()},4,1498)) goto _0;
			Obj t23;
			if (!g->GetValue(ctx,(PCV[]){t23.cv(),t22.cv(),nullptr})) goto _0;
			lerror=t23.get();
		}
		{
			Variant t24;
			c.f.fLine=16;
			if (g->GetMember(ctx,Parm<Obj>(inParams,2).cv(),Kevent.cv(),t24.cv())) goto _0;
			Bool t25;
			if (g->OperationOnAny(ctx,7,t24.cv(),Value_null().cv(),t25.cv())) goto _0;
			Bool t26;
			t26=t25.get();
			if (!(t25.get())) goto _6;
			{
				{
					Variant t27;
					if (g->GetMember(ctx,Parm<Obj>(inParams,2).cv(),Kevent.cv(),t27.cv())) goto _0;
					Obj t28;
					if (g->Call(ctx,(PCV[]){t28.cv()},0,1710)) goto _0;
					Variant t29;
					if (g->Call(ctx,(PCV[]){t29.cv(),t28.cv(),Kevent.cv(),Long(56).cv()},3,1496)) goto _0;
					g->Check(ctx);
					Variant t30;
					if (g->Call(ctx,(PCV[]){t30.cv(),t29.cv(),Kevent.cv(),Long(56).cv()},3,1496)) goto _0;
					Obj t31;
					if (!g->GetValue(ctx,(PCV[]){t31.cv(),t30.cv(),nullptr})) goto _0;
					Obj t32;
					if (!g->GetValue(ctx,(PCV[]){t32.cv(),t27.cv(),nullptr})) goto _0;
					Bool t33;
					if (g->Call(ctx,(PCV[]){t33.cv(),t32.cv(),t31.cv()},2,1731)) goto _0;
					t26=t33.get();
				}
			}
_6:
			if (!(t26.get())) goto _7;
		}
		{
			Variant t34;
			c.f.fLine=17;
			if (g->GetMember(ctx,Parm<Obj>(inParams,2).cv(),Kevent.cv(),t34.cv())) goto _0;
			Variant t35;
			if (g->GetMember(ctx,t34.cv(),KonError.cv(),t35.cv())) goto _0;
			Obj t36;
			if (g->Call(ctx,(PCV[]){t36.cv()},0,1470)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t35.cv(),Kcall.cv(),t36.cv(),Parm<Obj>(inParams,2).cv(),lerror.cv()},5,1500)) goto _0;
			g->Check(ctx);
		}
_7:
_5:
_0:
_1:
;
	}

}
extern Txt K__server;
extern Txt Knew;
extern Txt Kterminate;
extern Txt Kworker;
extern Txt Kworkers;
extern unsigned char D_proc___interface_2Eterminate[];
void proc___interface_2Eterminate( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___interface_2Eterminate);
	if (!ctx->doingAbort && c.f.fLine==0) {
		Obj lONNX;
		{
			Obj t0;
			c.f.fLine=3;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1710)) goto _0;
			Variant t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv(),Kworkers.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t2;
			if (g->Call(ctx,(PCV[]){t2.cv(),t1.cv(),Kworker.cv(),Long(56).cv()},3,1496)) goto _0;
			Obj t3;
			if (g->Call(ctx,(PCV[]){t3.cv()},0,1710)) goto _0;
			Variant t4;
			if (g->Call(ctx,(PCV[]){t4.cv(),t3.cv(),K__server.cv(),Long(56).cv()},3,1496)) goto _0;
			Variant t5;
			if (g->Call(ctx,(PCV[]){t5.cv(),t2.cv(),Knew.cv(),t4.cv()},3,1498)) goto _0;
			Obj t6;
			if (!g->GetValue(ctx,(PCV[]){t6.cv(),t5.cv(),nullptr})) goto _0;
			lONNX=t6.get();
		}
		c.f.fLine=4;
		if (g->Call(ctx,(PCV[]){nullptr,lONNX.cv(),Kterminate.cv()},2,1500)) goto _0;
		g->Check(ctx);
_0:
_1:
;
	}

}
extern unsigned char D_proc___interface_3Aconstructor[];
void proc___interface_3Aconstructor( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___interface_3Aconstructor);
	if (!ctx->doingAbort && c.f.fLine==0) {
_0:
_1:
;
	}

}
