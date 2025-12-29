extern Txt K__onResponse;
extern Txt K__onTerminate;
extern Txt K__worker;
extern Txt KonResponse;
extern Txt KonTerminate;
extern unsigned char D_proc___CLI__Controller_2E__terminate[];
void proc___CLI__Controller_2E__terminate( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI__Controller_2E__terminate);
	if (!ctx->doingAbort && c.f.fLine==0) {
		{
			Obj t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			Obj t1;
			if (g->Call(ctx,(PCV[]){t1.cv()},0,1470)) goto _0;
			Variant t2;
			if (g->Call(ctx,(PCV[]){t2.cv(),t1.cv(),K__onResponse.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,t0.cv(),KonResponse.cv(),t2.cv(),Long(56).cv()},4,1497)) goto _0;
		}
		{
			Obj t3;
			c.f.fLine=3;
			if (g->Call(ctx,(PCV[]){t3.cv()},0,1470)) goto _0;
			Obj t4;
			if (g->Call(ctx,(PCV[]){t4.cv()},0,1470)) goto _0;
			Variant t5;
			if (g->Call(ctx,(PCV[]){t5.cv(),t4.cv(),K__onTerminate.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,t3.cv(),KonTerminate.cv(),t5.cv(),Long(56).cv()},4,1497)) goto _0;
		}
		{
			Obj t6;
			c.f.fLine=4;
			if (g->Call(ctx,(PCV[]){t6.cv()},0,1470)) goto _0;
			Variant t7;
			t7.setNull();
			if (g->Call(ctx,(PCV[]){nullptr,t6.cv(),K__worker.cv(),t7.cv(),Long(56).cv()},4,1497)) goto _0;
			g->Check(ctx);
		}
_0:
_1:
;
	}

}
extern Txt K__commands;
extern Txt K__complete;
extern Txt Kclear;
extern unsigned char D_proc___CLI__Controller_2E__abort[];
void proc___CLI__Controller_2E__abort( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI__Controller_2E__abort);
	if (!ctx->doingAbort && c.f.fLine==0) {
		{
			Obj t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			Bool t1;
			t1=Bool(1).get();
			if (g->Call(ctx,(PCV[]){nullptr,t0.cv(),K__complete.cv(),t1.cv(),Long(10).cv()},4,1497)) goto _0;
			g->Check(ctx);
		}
		{
			Obj t2;
			c.f.fLine=3;
			if (g->Call(ctx,(PCV[]){t2.cv()},0,1470)) goto _0;
			Variant t3;
			if (g->Call(ctx,(PCV[]){t3.cv(),t2.cv(),K__commands.cv(),Long(57).cv()},3,1496)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,t3.cv(),Kclear.cv()},2,1500)) goto _0;
		}
_0:
_1:
;
	}

}
extern Txt KBlob;
extern Txt KSystemWorker;
extern Txt K__commands;
extern Txt K__complete;
extern Txt K__contexts;
extern Txt K__messages;
extern Txt K__worker;
extern Txt KcloseInput;
extern Txt Knew;
extern Txt Kpid;
extern Txt KpostMessage;
extern Txt Kshift;
extern Txt kJJuAI0lcGZk;
extern unsigned char D_proc___CLI__Controller_2E__execute[];
void proc___CLI__Controller_2E__execute( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI__Controller_2E__execute);
	if (!ctx->doingAbort && c.f.fLine==0) {
		Long lvt;
		Variant lmessage;
		{
			Obj t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			Bool t1;
			t1=Bool(0).get();
			if (g->Call(ctx,(PCV[]){nullptr,t0.cv(),K__complete.cv(),t1.cv(),Long(10).cv()},4,1497)) goto _0;
			g->Check(ctx);
		}
		{
			Obj t2;
			c.f.fLine=4;
			if (g->Call(ctx,(PCV[]){t2.cv()},0,1470)) goto _0;
			Obj t3;
			if (g->Call(ctx,(PCV[]){t3.cv()},0,1709)) goto _0;
			Variant t4;
			if (g->Call(ctx,(PCV[]){t4.cv(),t3.cv(),KSystemWorker.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Obj t5;
			if (g->Call(ctx,(PCV[]){t5.cv()},0,1470)) goto _0;
			Variant t6;
			if (g->Call(ctx,(PCV[]){t6.cv(),t5.cv(),K__commands.cv(),Long(57).cv()},3,1496)) goto _0;
			Variant t7;
			if (g->Call(ctx,(PCV[]){t7.cv(),t6.cv(),Kshift.cv()},2,1498)) goto _0;
			Obj t8;
			if (g->Call(ctx,(PCV[]){t8.cv()},0,1470)) goto _0;
			Variant t9;
			if (g->Call(ctx,(PCV[]){t9.cv(),t4.cv(),Knew.cv(),t7.cv(),t8.cv()},4,1498)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t2.cv(),K__worker.cv(),t9.cv(),Long(56).cv()},4,1497)) goto _0;
		}
		{
			Obj t10;
			c.f.fLine=6;
			if (g->Call(ctx,(PCV[]){t10.cv()},0,1470)) goto _0;
			Variant t11;
			if (g->Call(ctx,(PCV[]){t11.cv(),t10.cv(),kJJuAI0lcGZk.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Obj t12;
			if (g->Call(ctx,(PCV[]){t12.cv()},0,1470)) goto _0;
			Variant t13;
			if (g->Call(ctx,(PCV[]){t13.cv(),t12.cv(),K__worker.cv(),Long(56).cv()},3,1496)) goto _0;
			Variant t14;
			if (g->Call(ctx,(PCV[]){t14.cv(),t13.cv(),Kpid.cv(),Long(3).cv()},3,1496)) goto _0;
			Txt t15;
			if (g->Call(ctx,(PCV[]){t15.cv(),t14.cv()},1,10)) goto _0;
			Obj t16;
			if (g->Call(ctx,(PCV[]){t16.cv()},0,1470)) goto _0;
			Variant t17;
			if (g->Call(ctx,(PCV[]){t17.cv(),t16.cv(),K__contexts.cv(),Long(57).cv()},3,1496)) goto _0;
			Variant t18;
			if (g->Call(ctx,(PCV[]){t18.cv(),t17.cv(),Kshift.cv()},2,1498)) goto _0;
			if (g->SetMember(ctx,t11.cv(),t15.cv(),t18.cv())) goto _0;
		}
		{
			Obj t19;
			c.f.fLine=9;
			if (g->Call(ctx,(PCV[]){t19.cv()},0,1470)) goto _0;
			Variant t20;
			if (g->Call(ctx,(PCV[]){t20.cv(),t19.cv(),K__messages.cv(),Long(57).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t21;
			if (g->Call(ctx,(PCV[]){t21.cv(),t20.cv(),Kshift.cv()},2,1498)) goto _0;
			if (!g->SetValue(ctx,(PCV[]){t21.cv(),lmessage.cv(),nullptr})) goto _0;
		}
		{
			Variant t22;
			c.f.fLine=12;
			if (!g->GetValue(ctx,(PCV[]){t22.cv(),lmessage.cv(),nullptr})) goto _0;
			Long t23;
			if (g->Call(ctx,(PCV[]){t23.cv(),t22.cv()},1,1509)) goto _0;
			lvt=t23.get();
		}
		{
			Bool t24;
			t24=38==lvt.get();
			Bool t25;
			t25=t24.get();
			if (!(t24.get())) goto _2;
			{
				{
					Obj t26;
					c.f.fLine=14;
					if (g->Call(ctx,(PCV[]){t26.cv()},0,1709)) goto _0;
					Variant t27;
					if (g->Call(ctx,(PCV[]){t27.cv(),t26.cv(),KBlob.cv(),Long(56).cv()},3,1496)) goto _0;
					g->Check(ctx);
					Obj t28;
					if (!g->GetValue(ctx,(PCV[]){t28.cv(),t27.cv(),nullptr})) goto _0;
					Obj t29;
					if (!g->GetValue(ctx,(PCV[]){t29.cv(),lmessage.cv(),nullptr})) goto _0;
					Bool t30;
					if (g->Call(ctx,(PCV[]){t30.cv(),t29.cv(),t28.cv()},2,1731)) goto _0;
					t25=t30.get();
				}
			}
_2:
			if (!(t25.get())) goto _3;
		}
		lvt=30;
_3:
		{
			Bool t31;
			t31=38==lvt.get();
			Bool t32;
			t32=t31.get();
			if (t31.get()) goto _5;
			{
				t32=42==lvt.get();
			}
_5:
			if (!(t32.get())) goto _6;
		}
		{
			Obj t34;
			c.f.fLine=21;
			if (g->Call(ctx,(PCV[]){t34.cv()},0,1470)) goto _0;
			Variant t35;
			if (g->Call(ctx,(PCV[]){t35.cv(),t34.cv(),K__worker.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t36;
			if (!g->GetValue(ctx,(PCV[]){t36.cv(),lmessage.cv(),nullptr})) goto _0;
			Txt t37;
			if (g->Call(ctx,(PCV[]){t37.cv(),t36.cv()},1,1217)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t35.cv(),KpostMessage.cv(),t37.cv()},3,1500)) goto _0;
		}
		{
			Obj t38;
			c.f.fLine=22;
			if (g->Call(ctx,(PCV[]){t38.cv()},0,1470)) goto _0;
			Variant t39;
			if (g->Call(ctx,(PCV[]){t39.cv(),t38.cv(),K__worker.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,t39.cv(),KcloseInput.cv()},2,1500)) goto _0;
		}
		asm volatile("");
		goto _4;
_6:
		{
			Bool t40;
			t40=30==lvt.get();
			Bool t41;
			t41=t40.get();
			if (t40.get()) goto _7;
			{
				t41=2==lvt.get();
			}
_7:
			if (!(t41.get())) goto _8;
		}
		{
			Obj t43;
			c.f.fLine=26;
			if (g->Call(ctx,(PCV[]){t43.cv()},0,1470)) goto _0;
			Variant t44;
			if (g->Call(ctx,(PCV[]){t44.cv(),t43.cv(),K__worker.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t45;
			if (!g->GetValue(ctx,(PCV[]){t45.cv(),lmessage.cv(),nullptr})) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t44.cv(),KpostMessage.cv(),t45.cv()},3,1500)) goto _0;
		}
		{
			Obj t46;
			c.f.fLine=27;
			if (g->Call(ctx,(PCV[]){t46.cv()},0,1470)) goto _0;
			Variant t47;
			if (g->Call(ctx,(PCV[]){t47.cv(),t46.cv(),K__worker.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,t47.cv(),KcloseInput.cv()},2,1500)) goto _0;
		}
		asm volatile("");
		goto _4;
_8:
		{
			Bool t48;
			t48=1==lvt.get();
			Bool t49;
			t49=t48.get();
			if (t48.get()) goto _9;
			{
				t49=8==lvt.get();
			}
_9:
			Bool t51;
			t51=t49.get();
			if (t49.get()) goto _10;
			{
				t51=6==lvt.get();
			}
_10:
			Bool t53;
			t53=t51.get();
			if (t51.get()) goto _11;
			{
				t53=4==lvt.get();
			}
_11:
			Bool t55;
			t55=t53.get();
			if (t53.get()) goto _12;
			{
				t55=11==lvt.get();
			}
_12:
			if (!(t55.get())) goto _13;
		}
		{
			Obj t57;
			c.f.fLine=31;
			if (g->Call(ctx,(PCV[]){t57.cv()},0,1470)) goto _0;
			Variant t58;
			if (g->Call(ctx,(PCV[]){t58.cv(),t57.cv(),K__worker.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t59;
			if (!g->GetValue(ctx,(PCV[]){t59.cv(),lmessage.cv(),nullptr})) goto _0;
			Txt t60;
			if (g->Call(ctx,(PCV[]){t60.cv(),t59.cv()},1,10)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t58.cv(),KpostMessage.cv(),t60.cv()},3,1500)) goto _0;
		}
		{
			Obj t61;
			c.f.fLine=32;
			if (g->Call(ctx,(PCV[]){t61.cv()},0,1470)) goto _0;
			Variant t62;
			if (g->Call(ctx,(PCV[]){t62.cv(),t61.cv(),K__worker.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,t62.cv(),KcloseInput.cv()},2,1500)) goto _0;
		}
		asm volatile("");
		goto _4;
_13:
_4:
_0:
_1:
;
	}

}
extern Txt K__complete;
extern unsigned char D_proc___CLI__Controller_2Eget_20complete[];
void proc___CLI__Controller_2Eget_20complete( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI__Controller_2Eget_20complete);
	if (!ctx->doingAbort && c.f.fLine==0) {
		new ( outResult) Bool();
		{
			Obj t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			Variant t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv(),K__complete.cv(),Long(10).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Bool t2;
			if (!g->GetValue(ctx,(PCV[]){t2.cv(),t1.cv(),nullptr})) goto _0;
			Res<Bool>(outResult)=t2.get();
		}
_0:
_1:
;
	}

}
extern Txt KFunction;
extern Txt K__abort;
extern Txt K__commands;
extern Txt K__execute;
extern Txt K__onResponse;
extern Txt Kcall;
extern Txt Kcontext;
extern Txt Klength;
extern Txt Kpid;
extern Txt kJJuAI0lcGZk;
extern unsigned char D_proc___CLI__Controller_2E__onExecute[];
void proc___CLI__Controller_2E__onExecute( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI__Controller_2E__onExecute);
	if (!ctx->doingAbort && c.f.fLine==0) {
		{
			Obj t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			Variant t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv(),K__commands.cv(),Long(57).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t2;
			if (g->Call(ctx,(PCV[]){t2.cv(),t1.cv(),Klength.cv(),Long(4).cv()},3,1496)) goto _0;
			Bool t3;
			if (g->OperationOnAny(ctx,6,t2.cv(),Num(0).cv(),t3.cv())) goto _0;
			if (!(t3.get())) goto _2;
		}
		{
			Obj t4;
			c.f.fLine=3;
			if (g->Call(ctx,(PCV[]){t4.cv()},0,1470)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t4.cv(),K__abort.cv()},2,1500)) goto _0;
			g->Check(ctx);
		}
		asm volatile("");
		goto _3;
_2:
		{
			Obj t5;
			c.f.fLine=5;
			if (g->Call(ctx,(PCV[]){t5.cv()},0,1470)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t5.cv(),K__execute.cv()},2,1500)) goto _0;
			g->Check(ctx);
		}
_3:
		{
			Obj t6;
			c.f.fLine=8;
			if (g->Call(ctx,(PCV[]){t6.cv()},0,1470)) goto _0;
			Variant t7;
			if (g->Call(ctx,(PCV[]){t7.cv(),t6.cv(),K__onResponse.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Obj t8;
			if (g->Call(ctx,(PCV[]){t8.cv()},0,1709)) goto _0;
			Variant t9;
			if (g->Call(ctx,(PCV[]){t9.cv(),t8.cv(),KFunction.cv(),Long(56).cv()},3,1496)) goto _0;
			Obj t10;
			if (!g->GetValue(ctx,(PCV[]){t10.cv(),t9.cv(),nullptr})) goto _0;
			Obj t11;
			if (!g->GetValue(ctx,(PCV[]){t11.cv(),t7.cv(),nullptr})) goto _0;
			Bool t12;
			if (g->Call(ctx,(PCV[]){t12.cv(),t11.cv(),t10.cv()},2,1731)) goto _0;
			if (!(t12.get())) goto _4;
		}
		{
			Obj t13;
			c.f.fLine=9;
			if (g->Call(ctx,(PCV[]){t13.cv()},0,1470)) goto _0;
			Variant t14;
			if (g->Call(ctx,(PCV[]){t14.cv(),t13.cv(),kJJuAI0lcGZk.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t15;
			if (g->Call(ctx,(PCV[]){t15.cv(),Parm<Obj>(inParams,1).cv(),Kpid.cv(),Long(3).cv()},3,1496)) goto _0;
			Txt t16;
			if (g->Call(ctx,(PCV[]){t16.cv(),t15.cv()},1,10)) goto _0;
			Variant t17;
			if (g->GetMember(ctx,t14.cv(),t16.cv(),t17.cv())) goto _0;
			if (g->SetMember(ctx,Parm<Obj>(inParams,2).cv(),Kcontext.cv(),t17.cv())) goto _0;
		}
		{
			Obj t18;
			c.f.fLine=10;
			if (g->Call(ctx,(PCV[]){t18.cv()},0,1470)) goto _0;
			Variant t19;
			if (g->Call(ctx,(PCV[]){t19.cv(),t18.cv(),K__onResponse.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Obj t20;
			if (g->Call(ctx,(PCV[]){t20.cv()},0,1470)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t19.cv(),Kcall.cv(),t20.cv(),Parm<Obj>(inParams,1).cv(),Parm<Obj>(inParams,2).cv()},5,1500)) goto _0;
		}
_4:
_0:
_1:
;
	}

}
extern Txt KFunction;
extern Txt K__onTerminate;
extern Txt K__terminate;
extern Txt Kcall;
extern Txt Kcomplete;
extern unsigned char D_proc___CLI__Controller_2E__onComplete[];
void proc___CLI__Controller_2E__onComplete( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI__Controller_2E__onComplete);
	if (!ctx->doingAbort && c.f.fLine==0) {
		{
			Obj t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			Variant t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv(),K__onTerminate.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Obj t2;
			if (g->Call(ctx,(PCV[]){t2.cv()},0,1709)) goto _0;
			Variant t3;
			if (g->Call(ctx,(PCV[]){t3.cv(),t2.cv(),KFunction.cv(),Long(56).cv()},3,1496)) goto _0;
			Obj t4;
			if (!g->GetValue(ctx,(PCV[]){t4.cv(),t3.cv(),nullptr})) goto _0;
			Obj t5;
			if (!g->GetValue(ctx,(PCV[]){t5.cv(),t1.cv(),nullptr})) goto _0;
			Bool t6;
			if (g->Call(ctx,(PCV[]){t6.cv(),t5.cv(),t4.cv()},2,1731)) goto _0;
			if (!(t6.get())) goto _2;
		}
		{
			Obj t7;
			c.f.fLine=3;
			if (g->Call(ctx,(PCV[]){t7.cv()},0,1470)) goto _0;
			Variant t8;
			if (g->Call(ctx,(PCV[]){t8.cv(),t7.cv(),K__onTerminate.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Obj t9;
			if (g->Call(ctx,(PCV[]){t9.cv()},0,1470)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t8.cv(),Kcall.cv(),t9.cv(),Parm<Obj>(inParams,1).cv(),Parm<Obj>(inParams,2).cv()},5,1500)) goto _0;
		}
_2:
		{
			Obj t10;
			c.f.fLine=6;
			if (g->Call(ctx,(PCV[]){t10.cv()},0,1470)) goto _0;
			Variant t11;
			if (g->Call(ctx,(PCV[]){t11.cv(),t10.cv(),Kcomplete.cv(),Long(10).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Bool t12;
			if (!g->GetValue(ctx,(PCV[]){t12.cv(),t11.cv(),nullptr})) goto _0;
			if (!(t12.get())) goto _3;
		}
		{
			Obj t13;
			c.f.fLine=7;
			if (g->Call(ctx,(PCV[]){t13.cv()},0,1470)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t13.cv(),K__terminate.cv()},2,1500)) goto _0;
			g->Check(ctx);
		}
_3:
_0:
_1:
;
	}

}
extern Txt K__abort;
extern Txt K__terminate;
extern Txt K__worker;
extern Txt Kterminate;
extern unsigned char D_proc___CLI__Controller_2Eterminate[];
void proc___CLI__Controller_2Eterminate( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI__Controller_2Eterminate);
	if (!ctx->doingAbort && c.f.fLine==0) {
		{
			Obj t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t0.cv(),K__abort.cv()},2,1500)) goto _0;
			g->Check(ctx);
		}
		{
			Obj t1;
			c.f.fLine=4;
			if (g->Call(ctx,(PCV[]){t1.cv()},0,1470)) goto _0;
			Variant t2;
			if (g->Call(ctx,(PCV[]){t2.cv(),t1.cv(),K__worker.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Bool t3;
			if (g->OperationOnAny(ctx,7,t2.cv(),Value_null().cv(),t3.cv())) goto _0;
			if (!(t3.get())) goto _2;
		}
		{
			Obj t4;
			c.f.fLine=5;
			if (g->Call(ctx,(PCV[]){t4.cv()},0,1470)) goto _0;
			Variant t5;
			if (g->Call(ctx,(PCV[]){t5.cv(),t4.cv(),K__worker.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,t5.cv(),Kterminate.cv()},2,1500)) goto _0;
		}
_2:
		{
			Obj t6;
			c.f.fLine=8;
			if (g->Call(ctx,(PCV[]){t6.cv()},0,1470)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t6.cv(),K__terminate.cv()},2,1500)) goto _0;
			g->Check(ctx);
		}
_0:
_1:
;
	}

}
extern Txt K__commands;
extern Txt K__contexts;
extern Txt K__execute;
extern Txt K__messages;
extern Txt K__onComplete;
extern Txt K__onExecute;
extern Txt K__onResponse;
extern Txt K__onTerminate;
extern Txt K__worker;
extern Txt Kcombine;
extern Txt Klength;
extern Txt KonResponse;
extern Txt KonTerminate;
extern unsigned char D_proc___CLI__Controller_2Eexecute[];
void proc___CLI__Controller_2Eexecute( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI__Controller_2Eexecute);
	if (!ctx->doingAbort && c.f.fLine==0) {
		Col lcontexts;
		Col lmessages;
		Col lcommands;
		new ( outResult) Obj();
		{
			Variant t0;
			c.f.fLine=7;
			if (!g->GetValue(ctx,(PCV[]){t0.cv(),Parm<Variant>(inParams,1).cv(),nullptr})) goto _0;
			Long t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv()},1,1509)) goto _0;
			Bool t2;
			t2=2==t1.get();
			if (!(t2.get())) goto _3;
		}
		{
			Variant t3;
			c.f.fLine=8;
			if (!g->GetValue(ctx,(PCV[]){t3.cv(),Parm<Variant>(inParams,1).cv(),nullptr})) goto _0;
			Col t4;
			if (g->Call(ctx,(PCV[]){t4.cv(),t3.cv()},1,1472)) goto _0;
			g->Check(ctx);
			lcommands=t4.get();
		}
		{
			Variant t5;
			c.f.fLine=9;
			if (!g->GetValue(ctx,(PCV[]){t5.cv(),Parm<Variant>(inParams,2).cv(),nullptr})) goto _0;
			Col t6;
			if (g->Call(ctx,(PCV[]){t6.cv(),t5.cv()},1,1472)) goto _0;
			g->Check(ctx);
			lmessages=t6.get();
		}
		{
			Variant t7;
			c.f.fLine=10;
			if (!g->GetValue(ctx,(PCV[]){t7.cv(),Parm<Variant>(inParams,3).cv(),nullptr})) goto _0;
			Col t8;
			if (g->Call(ctx,(PCV[]){t8.cv(),t7.cv()},1,1472)) goto _0;
			g->Check(ctx);
			lcontexts=t8.get();
		}
		asm volatile("");
		goto _2;
_3:
		{
			Variant t9;
			c.f.fLine=11;
			if (!g->GetValue(ctx,(PCV[]){t9.cv(),Parm<Variant>(inParams,1).cv(),nullptr})) goto _0;
			Long t10;
			if (g->Call(ctx,(PCV[]){t10.cv(),t9.cv()},1,1509)) goto _0;
			Bool t11;
			t11=42==t10.get();
			if (!(t11.get())) goto _4;
		}
		{
			Col t12;
			c.f.fLine=12;
			if (!g->GetValue(ctx,(PCV[]){t12.cv(),Parm<Variant>(inParams,1).cv(),nullptr})) goto _0;
			lcommands=t12.get();
		}
		{
			Variant t13;
			c.f.fLine=13;
			if (!g->GetValue(ctx,(PCV[]){t13.cv(),Parm<Variant>(inParams,2).cv(),nullptr})) goto _0;
			Long t14;
			if (g->Call(ctx,(PCV[]){t14.cv(),t13.cv()},1,1509)) goto _0;
			Bool t15;
			t15=42==t14.get();
			Bool t16;
			t16=t15.get();
			if (!(t15.get())) goto _5;
			{
				{
					Variant t17;
					if (!g->GetValue(ctx,(PCV[]){t17.cv(),Parm<Variant>(inParams,2).cv(),nullptr})) goto _0;
					Variant t18;
					if (g->Call(ctx,(PCV[]){t18.cv(),t17.cv(),Klength.cv()},2,1496)) goto _0;
					g->Check(ctx);
					Variant t19;
					if (g->Call(ctx,(PCV[]){t19.cv(),lcommands.cv(),Klength.cv(),Long(4).cv()},3,1496)) goto _0;
					Bool t20;
					if (g->OperationOnAny(ctx,6,t18.cv(),t19.cv(),t20.cv())) goto _0;
					t16=t20.get();
				}
			}
_5:
			if (!(t16.get())) goto _6;
		}
		{
			Col t21;
			c.f.fLine=14;
			if (!g->GetValue(ctx,(PCV[]){t21.cv(),Parm<Variant>(inParams,2).cv(),nullptr})) goto _0;
			lmessages=t21.get();
		}
		asm volatile("");
		goto _7;
_6:
		{
			Variant t22;
			c.f.fLine=16;
			if (g->Call(ctx,(PCV[]){t22.cv(),lcommands.cv(),Klength.cv(),Long(4).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t23;
			if (g->OperationOnAny(ctx,1,t22.cv(),Num(1).cv(),t23.cv())) goto _0;
			Variant t24;
			t24.setNull();
			if (g->SetMember(ctx,lmessages.cv(),t23.cv(),t24.cv())) goto _0;
		}
_7:
		{
			Variant t25;
			c.f.fLine=18;
			if (!g->GetValue(ctx,(PCV[]){t25.cv(),Parm<Variant>(inParams,3).cv(),nullptr})) goto _0;
			Long t26;
			if (g->Call(ctx,(PCV[]){t26.cv(),t25.cv()},1,1509)) goto _0;
			Bool t27;
			t27=42==t26.get();
			Bool t28;
			t28=t27.get();
			if (!(t27.get())) goto _8;
			{
				{
					Variant t29;
					if (!g->GetValue(ctx,(PCV[]){t29.cv(),Parm<Variant>(inParams,3).cv(),nullptr})) goto _0;
					Variant t30;
					if (g->Call(ctx,(PCV[]){t30.cv(),t29.cv(),Klength.cv()},2,1496)) goto _0;
					g->Check(ctx);
					Variant t31;
					if (g->Call(ctx,(PCV[]){t31.cv(),lcommands.cv(),Klength.cv(),Long(4).cv()},3,1496)) goto _0;
					Bool t32;
					if (g->OperationOnAny(ctx,6,t30.cv(),t31.cv(),t32.cv())) goto _0;
					t28=t32.get();
				}
			}
_8:
			if (!(t28.get())) goto _9;
		}
		{
			Col t33;
			c.f.fLine=19;
			if (!g->GetValue(ctx,(PCV[]){t33.cv(),Parm<Variant>(inParams,3).cv(),nullptr})) goto _0;
			lcontexts=t33.get();
		}
		asm volatile("");
		goto _10;
_9:
		{
			Variant t34;
			c.f.fLine=21;
			if (g->Call(ctx,(PCV[]){t34.cv(),lcommands.cv(),Klength.cv(),Long(4).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t35;
			if (g->OperationOnAny(ctx,1,t34.cv(),Num(1).cv(),t35.cv())) goto _0;
			Variant t36;
			t36.setNull();
			if (g->SetMember(ctx,lcontexts.cv(),t35.cv(),t36.cv())) goto _0;
		}
_10:
		asm volatile("");
		goto _2;
_4:
_2:
		{
			Bool t37;
			t37=!lcommands.isNull();
			Bool t38;
			t38=t37.get();
			if (!(t37.get())) goto _11;
			{
				{
					Variant t39;
					c.f.fLine=25;
					if (g->Call(ctx,(PCV[]){t39.cv(),lcommands.cv(),Klength.cv(),Long(4).cv()},3,1496)) goto _0;
					g->Check(ctx);
					Bool t40;
					if (g->OperationOnAny(ctx,7,t39.cv(),Num(0).cv(),t40.cv())) goto _0;
					t38=t40.get();
				}
			}
_11:
			if (!(t38.get())) goto _12;
		}
		{
			Obj t41;
			c.f.fLine=27;
			if (g->Call(ctx,(PCV[]){t41.cv()},0,1470)) goto _0;
			Variant t42;
			if (g->Call(ctx,(PCV[]){t42.cv(),t41.cv(),K__commands.cv(),Long(57).cv()},3,1496)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,t42.cv(),Kcombine.cv(),lcommands.cv()},3,1500)) goto _0;
		}
		{
			Obj t43;
			c.f.fLine=28;
			if (g->Call(ctx,(PCV[]){t43.cv()},0,1470)) goto _0;
			Variant t44;
			if (g->Call(ctx,(PCV[]){t44.cv(),t43.cv(),K__messages.cv(),Long(57).cv()},3,1496)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,t44.cv(),Kcombine.cv(),lmessages.cv()},3,1500)) goto _0;
		}
		{
			Obj t45;
			c.f.fLine=29;
			if (g->Call(ctx,(PCV[]){t45.cv()},0,1470)) goto _0;
			Variant t46;
			if (g->Call(ctx,(PCV[]){t46.cv(),t45.cv(),K__contexts.cv(),Long(57).cv()},3,1496)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,t46.cv(),Kcombine.cv(),lcontexts.cv()},3,1500)) goto _0;
		}
		{
			Obj t47;
			c.f.fLine=31;
			if (g->Call(ctx,(PCV[]){t47.cv()},0,1470)) goto _0;
			Variant t48;
			if (g->Call(ctx,(PCV[]){t48.cv(),t47.cv(),K__worker.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Bool t49;
			if (g->OperationOnAny(ctx,6,t48.cv(),Value_null().cv(),t49.cv())) goto _0;
			if (!(t49.get())) goto _13;
		}
		{
			Obj t50;
			c.f.fLine=32;
			if (g->Call(ctx,(PCV[]){t50.cv()},0,1470)) goto _0;
			Obj t51;
			if (g->Call(ctx,(PCV[]){t51.cv()},0,1470)) goto _0;
			Variant t52;
			if (g->Call(ctx,(PCV[]){t52.cv(),t51.cv(),KonResponse.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,t50.cv(),K__onResponse.cv(),t52.cv(),Long(56).cv()},4,1497)) goto _0;
		}
		{
			Obj t53;
			c.f.fLine=33;
			if (g->Call(ctx,(PCV[]){t53.cv()},0,1470)) goto _0;
			Obj t54;
			if (g->Call(ctx,(PCV[]){t54.cv()},0,1470)) goto _0;
			Variant t55;
			if (g->GetMember(ctx,t54.cv(),K__onExecute.cv(),t55.cv())) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t53.cv(),KonResponse.cv(),t55.cv(),Long(56).cv()},4,1497)) goto _0;
			g->Check(ctx);
		}
		{
			Obj t56;
			c.f.fLine=34;
			if (g->Call(ctx,(PCV[]){t56.cv()},0,1470)) goto _0;
			Obj t57;
			if (g->Call(ctx,(PCV[]){t57.cv()},0,1470)) goto _0;
			Variant t58;
			if (g->Call(ctx,(PCV[]){t58.cv(),t57.cv(),KonTerminate.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,t56.cv(),K__onTerminate.cv(),t58.cv(),Long(56).cv()},4,1497)) goto _0;
		}
		{
			Obj t59;
			c.f.fLine=35;
			if (g->Call(ctx,(PCV[]){t59.cv()},0,1470)) goto _0;
			Obj t60;
			if (g->Call(ctx,(PCV[]){t60.cv()},0,1470)) goto _0;
			Variant t61;
			if (g->GetMember(ctx,t60.cv(),K__onComplete.cv(),t61.cv())) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t59.cv(),KonTerminate.cv(),t61.cv(),Long(56).cv()},4,1497)) goto _0;
			g->Check(ctx);
		}
		{
			Obj t62;
			c.f.fLine=36;
			if (g->Call(ctx,(PCV[]){t62.cv()},0,1470)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t62.cv(),K__execute.cv()},2,1500)) goto _0;
			g->Check(ctx);
		}
_13:
_12:
		{
			Obj t63;
			c.f.fLine=41;
			if (g->Call(ctx,(PCV[]){t63.cv()},0,1470)) goto _0;
			Res<Obj>(outResult)=t63.get();
		}
		asm volatile("");
		goto _0;
_0:
_1:
;
	}

}
extern Txt K__instance;
extern unsigned char D_proc___CLI__Controller_2Eget_20instance[];
void proc___CLI__Controller_2Eget_20instance( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI__Controller_2Eget_20instance);
	if (!ctx->doingAbort && c.f.fLine==0) {
		new ( outResult) Obj();
		{
			Obj t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			Variant t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv(),K__instance.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Obj t2;
			if (!g->GetValue(ctx,(PCV[]){t2.cv(),t1.cv(),nullptr})) goto _0;
			Res<Obj>(outResult)=t2.get();
		}
_0:
_1:
;
	}

}
extern Txt Kblob;
extern Txt Kdata;
extern Txt KdataType;
extern Txt Kerror;
extern Txt Kresponse;
extern Txt Ktermination;
extern Txt Ktext;
extern Txt Ktype;
extern unsigned char D_proc___CLI__Controller_2E__onEvent[];
void proc___CLI__Controller_2E__onEvent( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI__Controller_2E__onEvent);
	if (!ctx->doingAbort && c.f.fLine==0) {
		{
			Variant t0;
			c.f.fLine=3;
			if (g->GetMember(ctx,Parm<Obj>(inParams,2).cv(),Ktype.cv(),t0.cv())) goto _0;
			Bool t1;
			if (g->OperationOnAny(ctx,6,t0.cv(),Kdata.cv(),t1.cv())) goto _0;
			Bool t2;
			t2=t1.get();
			if (!(t1.get())) goto _3;
			{
				{
					Variant t3;
					if (g->Call(ctx,(PCV[]){t3.cv(),Parm<Obj>(inParams,1).cv(),KdataType.cv(),Long(11).cv()},3,1496)) goto _0;
					g->Check(ctx);
					Bool t4;
					if (g->OperationOnAny(ctx,6,t3.cv(),Ktext.cv(),t4.cv())) goto _0;
					t2=t4.get();
				}
			}
_3:
			if (!(t2.get())) goto _4;
		}
		asm volatile("");
		goto _2;
_4:
		{
			Variant t5;
			c.f.fLine=5;
			if (g->GetMember(ctx,Parm<Obj>(inParams,2).cv(),Ktype.cv(),t5.cv())) goto _0;
			Bool t6;
			if (g->OperationOnAny(ctx,6,t5.cv(),Kdata.cv(),t6.cv())) goto _0;
			Bool t7;
			t7=t6.get();
			if (!(t6.get())) goto _5;
			{
				{
					Variant t8;
					if (g->Call(ctx,(PCV[]){t8.cv(),Parm<Obj>(inParams,1).cv(),KdataType.cv(),Long(11).cv()},3,1496)) goto _0;
					g->Check(ctx);
					Bool t9;
					if (g->OperationOnAny(ctx,6,t8.cv(),Kblob.cv(),t9.cv())) goto _0;
					t7=t9.get();
				}
			}
_5:
			if (!(t7.get())) goto _6;
		}
		asm volatile("");
		goto _2;
_6:
		{
			Variant t10;
			c.f.fLine=7;
			if (g->GetMember(ctx,Parm<Obj>(inParams,2).cv(),Ktype.cv(),t10.cv())) goto _0;
			Bool t11;
			if (g->OperationOnAny(ctx,6,t10.cv(),Kerror.cv(),t11.cv())) goto _0;
			if (!(t11.get())) goto _7;
		}
		asm volatile("");
		goto _2;
_7:
		{
			Variant t12;
			c.f.fLine=9;
			if (g->GetMember(ctx,Parm<Obj>(inParams,2).cv(),Ktype.cv(),t12.cv())) goto _0;
			Bool t13;
			if (g->OperationOnAny(ctx,6,t12.cv(),Ktermination.cv(),t13.cv())) goto _0;
			if (!(t13.get())) goto _8;
		}
		asm volatile("");
		goto _2;
_8:
		{
			Variant t14;
			c.f.fLine=11;
			if (g->GetMember(ctx,Parm<Obj>(inParams,2).cv(),Ktype.cv(),t14.cv())) goto _0;
			Bool t15;
			if (g->OperationOnAny(ctx,6,t14.cv(),Kresponse.cv(),t15.cv())) goto _0;
			if (!(t15.get())) goto _9;
		}
		asm volatile("");
		goto _2;
_9:
_2:
_0:
_1:
;
	}

}
extern Txt K__worker;
extern unsigned char D_proc___CLI__Controller_2Eget_20worker[];
void proc___CLI__Controller_2Eget_20worker( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI__Controller_2Eget_20worker);
	if (!ctx->doingAbort && c.f.fLine==0) {
		new ( outResult) Obj();
		{
			Obj t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			Variant t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv(),K__worker.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Obj t2;
			if (!g->GetValue(ctx,(PCV[]){t2.cv(),t1.cv(),nullptr})) goto _0;
			Res<Obj>(outResult)=t2.get();
		}
_0:
_1:
;
	}

}
extern Txt K__commands;
extern unsigned char D_proc___CLI__Controller_2Eget_20commands[];
void proc___CLI__Controller_2Eget_20commands( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI__Controller_2Eget_20commands);
	if (!ctx->doingAbort && c.f.fLine==0) {
		new ( outResult) Col();
		{
			Obj t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			Variant t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv(),K__commands.cv(),Long(57).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Col t2;
			if (!g->GetValue(ctx,(PCV[]){t2.cv(),t1.cv(),nullptr})) goto _0;
			Res<Col>(outResult)=t2.get();
		}
_0:
_1:
;
	}

}
extern Txt KFunction;
extern Txt KUTF_2D8;
extern Txt K__commands;
extern Txt K__complete;
extern Txt K__contexts;
extern Txt K__instance;
extern Txt K__messages;
extern Txt K__onEvent;
extern Txt K__worker;
extern Txt KdataType;
extern Txt Kencoding;
extern Txt KhideWindow;
extern Txt KonData;
extern Txt KonDataError;
extern Txt KonError;
extern Txt KonResponse;
extern Txt KonTerminate;
extern Txt Ktext;
extern Txt Ktimeout;
extern Txt Kvariables;
extern Txt k2y$RrLLxafc;
extern Txt kJJuAI0lcGZk;
extern unsigned char D_proc___CLI__Controller_3Aconstructor[];
void proc___CLI__Controller_3Aconstructor( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI__Controller_3Aconstructor);
	if (!ctx->doingAbort && c.f.fLine==0) {
		Variant levent;
		Obj l__4D__auto__iter__0;
		{
			Col t0;
			c.f.fLine=3;
			if (g->Call(ctx,(PCV[]){t0.cv(),KonData.cv(),KonDataError.cv(),KonError.cv(),KonResponse.cv(),KonTerminate.cv()},5,1472)) goto _0;
			g->Check(ctx);
			Ref t1;
			if (!g->CastPointerToRef(ctx,5,(PCV[]){t1.cv(),levent.cv(),nullptr})) goto _0;
			Obj t2;
			if (g->Call(ctx,(PCV[]){t2.cv(),t1.cv(),t0.cv()},2,1795)) goto _0;
			l__4D__auto__iter__0=t2.get();
		}
_2:
		{
			Bool t3;
			if (g->Call(ctx,(PCV[]){t3.cv(),l__4D__auto__iter__0.cv()},1,1796)) goto _0;
			if (!(t3.get())) goto _3;
		}
		{
			Obj t4;
			c.f.fLine=4;
			if (g->Call(ctx,(PCV[]){t4.cv()},0,1470)) goto _0;
			Variant t5;
			if (!g->GetValue(ctx,(PCV[]){t5.cv(),levent.cv(),nullptr})) goto _0;
			Variant t6;
			if (g->GetMember(ctx,t4.cv(),t5.cv(),t6.cv())) goto _0;
			Obj t7;
			if (g->Call(ctx,(PCV[]){t7.cv()},0,1709)) goto _0;
			Variant t8;
			if (g->Call(ctx,(PCV[]){t8.cv(),t7.cv(),KFunction.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Obj t9;
			if (!g->GetValue(ctx,(PCV[]){t9.cv(),t8.cv(),nullptr})) goto _0;
			Obj t10;
			if (!g->GetValue(ctx,(PCV[]){t10.cv(),t6.cv(),nullptr})) goto _0;
			Bool t11;
			if (g->Call(ctx,(PCV[]){t11.cv(),t10.cv(),t9.cv()},2,1731)) goto _0;
			Bool t12;
			t12=t11.get();
			Bool t13;
			t13=!(t12.get());
			if (!(t13.get())) goto _4;
		}
		{
			Obj t14;
			c.f.fLine=5;
			if (g->Call(ctx,(PCV[]){t14.cv()},0,1470)) goto _0;
			Obj t15;
			if (g->Call(ctx,(PCV[]){t15.cv()},0,1470)) goto _0;
			Variant t16;
			if (g->GetMember(ctx,t15.cv(),K__onEvent.cv(),t16.cv())) goto _0;
			Variant t17;
			if (!g->GetValue(ctx,(PCV[]){t17.cv(),levent.cv(),nullptr})) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t14.cv(),t17.cv(),t16.cv()},3,1497)) goto _0;
			g->Check(ctx);
		}
_4:
		asm volatile("");
		goto _2;
_3:
		{
			Obj t18;
			l__4D__auto__iter__0=t18.get();
		}
		{
			Obj t19;
			c.f.fLine=9;
			if (g->Call(ctx,(PCV[]){t19.cv()},0,1470)) goto _0;
			Variant t20;
			t20.setNull();
			if (g->Call(ctx,(PCV[]){nullptr,t19.cv(),Ktimeout.cv(),t20.cv(),Long(19).cv()},4,1497)) goto _0;
			g->Check(ctx);
		}
		{
			Obj t21;
			c.f.fLine=10;
			if (g->Call(ctx,(PCV[]){t21.cv()},0,1470)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t21.cv(),KdataType.cv(),Ktext.cv(),Long(11).cv()},4,1497)) goto _0;
			g->Check(ctx);
		}
		{
			Obj t22;
			c.f.fLine=11;
			if (g->Call(ctx,(PCV[]){t22.cv()},0,1470)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t22.cv(),Kencoding.cv(),KUTF_2D8.cv(),Long(11).cv()},4,1497)) goto _0;
			g->Check(ctx);
		}
		{
			Obj t23;
			c.f.fLine=12;
			if (g->Call(ctx,(PCV[]){t23.cv()},0,1470)) goto _0;
			Obj t24;
			if (g->Call(ctx,(PCV[]){t24.cv()},0,1471)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,t23.cv(),Kvariables.cv(),t24.cv(),Long(56).cv()},4,1497)) goto _0;
		}
		{
			Obj t25;
			c.f.fLine=13;
			if (g->Call(ctx,(PCV[]){t25.cv()},0,1470)) goto _0;
			Variant t26;
			if (g->Call(ctx,(PCV[]){t26.cv(),Parm<Obj>(inParams,1).cv(),k2y$RrLLxafc.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,t25.cv(),k2y$RrLLxafc.cv(),t26.cv(),Long(56).cv()},4,1497)) goto _0;
		}
		{
			Obj t27;
			c.f.fLine=14;
			if (g->Call(ctx,(PCV[]){t27.cv()},0,1470)) goto _0;
			Bool t28;
			t28=Bool(1).get();
			if (g->Call(ctx,(PCV[]){nullptr,t27.cv(),KhideWindow.cv(),t28.cv(),Long(10).cv()},4,1497)) goto _0;
			g->Check(ctx);
		}
		{
			Obj t29;
			c.f.fLine=16;
			if (g->Call(ctx,(PCV[]){t29.cv()},0,1470)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t29.cv(),K__instance.cv(),Parm<Obj>(inParams,1).cv(),Long(56).cv()},4,1497)) goto _0;
			g->Check(ctx);
		}
		{
			Obj t30;
			c.f.fLine=17;
			if (g->Call(ctx,(PCV[]){t30.cv()},0,1470)) goto _0;
			Col t31;
			if (g->Call(ctx,(PCV[]){t31.cv()},0,1472)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,t30.cv(),K__commands.cv(),t31.cv(),Long(57).cv()},4,1497)) goto _0;
		}
		{
			Obj t32;
			c.f.fLine=18;
			if (g->Call(ctx,(PCV[]){t32.cv()},0,1470)) goto _0;
			Col t33;
			if (g->Call(ctx,(PCV[]){t33.cv()},0,1472)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,t32.cv(),K__messages.cv(),t33.cv(),Long(57).cv()},4,1497)) goto _0;
		}
		{
			Obj t34;
			c.f.fLine=19;
			if (g->Call(ctx,(PCV[]){t34.cv()},0,1470)) goto _0;
			Col t35;
			if (g->Call(ctx,(PCV[]){t35.cv()},0,1472)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,t34.cv(),K__contexts.cv(),t35.cv(),Long(57).cv()},4,1497)) goto _0;
		}
		{
			Obj t36;
			c.f.fLine=20;
			if (g->Call(ctx,(PCV[]){t36.cv()},0,1470)) goto _0;
			Variant t37;
			t37.setNull();
			if (g->Call(ctx,(PCV[]){nullptr,t36.cv(),K__worker.cv(),t37.cv(),Long(56).cv()},4,1497)) goto _0;
			g->Check(ctx);
		}
		{
			Obj t38;
			c.f.fLine=21;
			if (g->Call(ctx,(PCV[]){t38.cv()},0,1470)) goto _0;
			Bool t39;
			t39=Bool(0).get();
			if (g->Call(ctx,(PCV[]){nullptr,t38.cv(),K__complete.cv(),t39.cv(),Long(10).cv()},4,1497)) goto _0;
			g->Check(ctx);
		}
		{
			Obj t40;
			c.f.fLine=22;
			if (g->Call(ctx,(PCV[]){t40.cv()},0,1470)) goto _0;
			Obj t41;
			if (g->Call(ctx,(PCV[]){t41.cv()},0,1471)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,t40.cv(),kJJuAI0lcGZk.cv(),t41.cv(),Long(56).cv()},4,1497)) goto _0;
		}
_0:
_1:
;
	}

}
