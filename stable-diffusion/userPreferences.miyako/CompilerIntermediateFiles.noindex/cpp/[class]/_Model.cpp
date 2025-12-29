extern Txt K__server;
extern Txt Kcall;
extern Txt Kevent;
extern Txt Kmodels;
extern Txt Knew;
extern Txt KonSuccess;
extern Txt Koptions;
extern Txt Kport;
extern Txt Kstart;
extern Txt Kworker;
extern Txt Kworkers;
extern unsigned char D_proc___Model_2Estart[];
void proc___Model_2Estart( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___Model_2Estart);
	if (!ctx->doingAbort && c.f.fLine==0) {
		Obj lONNX;
		{
			Obj t0;
			c.f.fLine=6;
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
		{
			Obj t7;
			c.f.fLine=7;
			if (g->Call(ctx,(PCV[]){t7.cv()},0,1470)) goto _0;
			Variant t8;
			if (g->Call(ctx,(PCV[]){t8.cv(),t7.cv(),Koptions.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t9;
			if (g->GetMember(ctx,t8.cv(),Kport.cv(),t9.cv())) goto _0;
			Obj t10;
			if (g->Call(ctx,(PCV[]){t10.cv()},0,1470)) goto _0;
			Variant t11;
			if (g->Call(ctx,(PCV[]){t11.cv(),t10.cv(),Koptions.cv(),Long(56).cv()},3,1496)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,lONNX.cv(),Kstart.cv(),t9.cv(),t11.cv()},4,1500)) goto _0;
		}
		{
			Obj t12;
			c.f.fLine=9;
			if (g->Call(ctx,(PCV[]){t12.cv()},0,1470)) goto _0;
			Variant t13;
			if (g->Call(ctx,(PCV[]){t13.cv(),t12.cv(),Kevent.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Bool t14;
			if (g->OperationOnAny(ctx,7,t13.cv(),Value_null().cv(),t14.cv())) goto _0;
			Bool t15;
			t15=t14.get();
			if (!(t14.get())) goto _2;
			{
				{
					Obj t16;
					if (g->Call(ctx,(PCV[]){t16.cv()},0,1470)) goto _0;
					Variant t17;
					if (g->Call(ctx,(PCV[]){t17.cv(),t16.cv(),Kevent.cv(),Long(56).cv()},3,1496)) goto _0;
					Obj t18;
					if (g->Call(ctx,(PCV[]){t18.cv()},0,1710)) goto _0;
					Variant t19;
					if (g->Call(ctx,(PCV[]){t19.cv(),t18.cv(),Kevent.cv(),Long(56).cv()},3,1496)) goto _0;
					Variant t20;
					if (g->Call(ctx,(PCV[]){t20.cv(),t19.cv(),Kevent.cv(),Long(56).cv()},3,1496)) goto _0;
					Obj t21;
					if (!g->GetValue(ctx,(PCV[]){t21.cv(),t20.cv(),nullptr})) goto _0;
					Obj t22;
					if (!g->GetValue(ctx,(PCV[]){t22.cv(),t17.cv(),nullptr})) goto _0;
					Bool t23;
					if (g->Call(ctx,(PCV[]){t23.cv(),t22.cv(),t21.cv()},2,1731)) goto _0;
					t15=t23.get();
				}
			}
_2:
			if (!(t15.get())) goto _3;
		}
		{
			Obj t24;
			c.f.fLine=10;
			if (g->Call(ctx,(PCV[]){t24.cv()},0,1470)) goto _0;
			Variant t25;
			if (g->Call(ctx,(PCV[]){t25.cv(),t24.cv(),Kevent.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t26;
			if (g->GetMember(ctx,t25.cv(),KonSuccess.cv(),t26.cv())) goto _0;
			Obj t27;
			if (g->Call(ctx,(PCV[]){t27.cv()},0,1470)) goto _0;
			Obj t28;
			if (g->Call(ctx,(PCV[]){t28.cv()},0,1470)) goto _0;
			Variant t29;
			if (g->Call(ctx,(PCV[]){t29.cv(),t28.cv(),Koptions.cv(),Long(56).cv()},3,1496)) goto _0;
			Obj t30;
			if (g->Call(ctx,(PCV[]){t30.cv()},0,1470)) goto _0;
			Variant t31;
			if (g->Call(ctx,(PCV[]){t31.cv(),t30.cv(),Kmodels.cv()},2,1498)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t26.cv(),Kcall.cv(),t27.cv(),t29.cv(),t31.cv()},5,1500)) goto _0;
		}
_3:
_0:
_1:
;
	}

}
extern Txt Kchat_2Ecompletion;
extern Txt Kdomain;
extern Txt Kembedding;
extern Txt Kfiles;
extern Txt Kfirst;
extern Txt Kfolder;
extern Txt Koid_20_3D_3D_20_3A1;
extern Txt KonDownload;
extern Txt Koptions;
extern Txt Kparent;
extern Txt Kpath;
extern Txt Kquery;
extern Txt k5pd6qQIgcLQ;
extern Txt kcVtzG12P014;
extern unsigned char D_proc___Model_2EonDownload[];
void proc___Model_2EonDownload( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___Model_2EonDownload);
	if (!ctx->doingAbort && c.f.fLine==0) {
		Obj ldownloaded;
		{
			Obj t0;
			c.f.fLine=3;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			Variant t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv(),Kfiles.cv(),Long(57).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t2;
			if (g->Call(ctx,(PCV[]){t2.cv(),t1.cv(),Kquery.cv(),Koid_20_3D_3D_20_3A1.cv(),Parm<Txt>(inParams,1).cv()},4,1498)) goto _0;
			Variant t3;
			if (g->Call(ctx,(PCV[]){t3.cv(),t2.cv(),Kfirst.cv()},2,1498)) goto _0;
			Obj t4;
			if (!g->GetValue(ctx,(PCV[]){t4.cv(),t3.cv(),nullptr})) goto _0;
			ldownloaded=t4.get();
		}
		{
			Bool t5;
			t5=!ldownloaded.isNull();
			if (!(t5.get())) goto _2;
		}
		{
			Variant t6;
			c.f.fLine=7;
			if (g->Call(ctx,(PCV[]){t6.cv(),ldownloaded.cv(),Kdomain.cv(),Long(11).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Bool t7;
			if (g->OperationOnAny(ctx,6,t6.cv(),Kchat_2Ecompletion.cv(),t7.cv())) goto _0;
			if (!(t7.get())) goto _4;
		}
		{
			Obj t8;
			c.f.fLine=8;
			if (g->Call(ctx,(PCV[]){t8.cv()},0,1470)) goto _0;
			Variant t9;
			if (g->Call(ctx,(PCV[]){t9.cv(),t8.cv(),Koptions.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t10;
			if (g->Call(ctx,(PCV[]){t10.cv(),ldownloaded.cv(),Kfolder.cv(),Long(56).cv()},3,1496)) goto _0;
			Variant t11;
			if (g->Call(ctx,(PCV[]){t11.cv(),ldownloaded.cv(),Kpath.cv(),Long(11).cv()},3,1496)) goto _0;
			Variant t12;
			if (g->Call(ctx,(PCV[]){t12.cv(),t10.cv(),Kfolder.cv(),t11.cv()},3,1498)) goto _0;
			Variant t13;
			if (g->Call(ctx,(PCV[]){t13.cv(),t12.cv(),Kparent.cv(),Long(56).cv()},3,1496)) goto _0;
			if (g->SetMember(ctx,t9.cv(),k5pd6qQIgcLQ.cv(),t13.cv())) goto _0;
		}
		asm volatile("");
		goto _3;
_4:
		{
			Variant t14;
			c.f.fLine=9;
			if (g->Call(ctx,(PCV[]){t14.cv(),ldownloaded.cv(),Kdomain.cv(),Long(11).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Bool t15;
			if (g->OperationOnAny(ctx,6,t14.cv(),Kembedding.cv(),t15.cv())) goto _0;
			if (!(t15.get())) goto _5;
		}
		{
			Obj t16;
			c.f.fLine=10;
			if (g->Call(ctx,(PCV[]){t16.cv()},0,1470)) goto _0;
			Variant t17;
			if (g->Call(ctx,(PCV[]){t17.cv(),t16.cv(),Koptions.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t18;
			if (g->Call(ctx,(PCV[]){t18.cv(),ldownloaded.cv(),Kfolder.cv(),Long(56).cv()},3,1496)) goto _0;
			Variant t19;
			if (g->Call(ctx,(PCV[]){t19.cv(),ldownloaded.cv(),Kpath.cv(),Long(11).cv()},3,1496)) goto _0;
			Variant t20;
			if (g->Call(ctx,(PCV[]){t20.cv(),t18.cv(),Kfolder.cv(),t19.cv()},3,1498)) goto _0;
			Variant t21;
			if (g->Call(ctx,(PCV[]){t21.cv(),t20.cv(),Kparent.cv(),Long(56).cv()},3,1496)) goto _0;
			if (g->SetMember(ctx,t17.cv(),kcVtzG12P014.cv(),t21.cv())) goto _0;
		}
		asm volatile("");
		goto _3;
_5:
_3:
_2:
		{
			Obj t22;
			c.f.fLine=14;
			if (g->Call(ctx,(PCV[]){t22.cv()},0,1706)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t22.cv(),KonDownload.cv(),Parm<Txt>(inParams,1).cv()},3,1500)) goto _0;
			g->Check(ctx);
		}
_0:
_1:
;
	}

}
extern Txt K__models;
extern Txt Kevent;
extern Txt Kmodel;
extern Txt Kmodels;
extern Txt Knew;
extern Txt Kpush;
extern unsigned char D_proc___Model_2Emodels[];
void proc___Model_2Emodels( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___Model_2Emodels);
	if (!ctx->doingAbort && c.f.fLine==0) {
		Obj l__4D__auto__iter__0;
		Txt l__model;
		Col lmodels;
		new ( outResult) Obj();
		{
			Col t0;
			c.f.fLine=3;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1472)) goto _0;
			g->Check(ctx);
			lmodels=t0.get();
		}
		{
			Obj t1;
			c.f.fLine=6;
			if (g->Call(ctx,(PCV[]){t1.cv()},0,1470)) goto _0;
			Variant t2;
			if (g->Call(ctx,(PCV[]){t2.cv(),t1.cv(),K__models.cv(),Long(57).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Ref t3;
			t3.setLocalRef(ctx,l__model.cv());
			Obj t4;
			if (g->Call(ctx,(PCV[]){t4.cv(),t3.cv(),t2.cv()},2,1795)) goto _0;
			l__4D__auto__iter__0=t4.get();
		}
_2:
		{
			Bool t5;
			if (g->Call(ctx,(PCV[]){t5.cv(),l__4D__auto__iter__0.cv()},1,1796)) goto _0;
			if (!(t5.get())) goto _3;
		}
		{
			Obj t6;
			c.f.fLine=7;
			if (g->Call(ctx,(PCV[]){t6.cv()},0,1710)) goto _0;
			Variant t7;
			if (g->Call(ctx,(PCV[]){t7.cv(),t6.cv(),Kevent.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t8;
			if (g->Call(ctx,(PCV[]){t8.cv(),t7.cv(),Kmodel.cv(),Long(56).cv()},3,1496)) goto _0;
			Bool t9;
			t9=Bool(1).get();
			Variant t10;
			if (g->Call(ctx,(PCV[]){t10.cv(),t8.cv(),Knew.cv(),l__model.cv(),t9.cv()},4,1498)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,lmodels.cv(),Kpush.cv(),t10.cv()},3,1500)) goto _0;
		}
		asm volatile("");
		goto _2;
_3:
		{
			Obj t11;
			l__4D__auto__iter__0=t11.get();
		}
		{
			Obj t12;
			c.f.fLine=10;
			if (g->Call(ctx,(PCV[]){t12.cv()},0,1710)) goto _0;
			Variant t13;
			if (g->Call(ctx,(PCV[]){t13.cv(),t12.cv(),Kevent.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t14;
			if (g->Call(ctx,(PCV[]){t14.cv(),t13.cv(),Kmodels.cv(),Long(56).cv()},3,1496)) goto _0;
			Variant t15;
			if (g->Call(ctx,(PCV[]){t15.cv(),t14.cv(),Knew.cv(),lmodels.cv()},3,1498)) goto _0;
			Obj t16;
			if (!g->GetValue(ctx,(PCV[]){t16.cv(),t15.cv(),nullptr})) goto _0;
			Res<Obj>(outResult)=t16.get();
		}
		asm volatile("");
		goto _0;
_0:
_1:
;
	}

}
extern Txt Kdownload;
extern unsigned char D_proc___Model_3Aconstructor[];
void proc___Model_3Aconstructor( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___Model_3Aconstructor);
	if (!ctx->doingAbort && c.f.fLine==0) {
		c.f.fLine=2;
		if (g->Call(ctx,(PCV[]){nullptr,Parm<Long>(inParams,1).cv(),Parm<Obj>(inParams,2).cv(),Parm<Obj>(inParams,3).cv(),Parm<Obj>(inParams,4).cv(),Parm<Obj>(inParams,5).cv()},5,1705)) goto _0;
		{
			Obj t0;
			c.f.fLine=4;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t0.cv(),Kdownload.cv()},2,1500)) goto _0;
			g->Check(ctx);
		}
_0:
_1:
;
	}

}
