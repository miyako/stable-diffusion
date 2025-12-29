extern Txt K_2E;
extern Txt K__onTCP;
extern Txt Kevent;
extern Txt Kfirst;
extern Txt Khuggingfaces;
extern Txt Kname;
extern Txt Koptions;
extern Txt Kport;
Asm4d_Proc proc_MAIN;
extern unsigned char D_proc_ONNX_2E__main[];
void proc_ONNX_2E__main( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc_ONNX_2E__main);
	if (!ctx->doingAbort && c.f.fLine==0) {
		{
			Txt t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,684)) goto _0;
			g->Check(ctx);
			Col t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv(),K_2E.cv(),Long(2).cv()},3,1554)) goto _0;
			Variant t2;
			if (g->Call(ctx,(PCV[]){t2.cv(),t1.cv(),Kfirst.cv()},2,1498)) goto _0;
			Obj t3;
			if (g->Call(ctx,(PCV[]){t3.cv(),Kname.cv(),t2.cv(),Kport.cv(),Parm<Long>(inParams,1).cv(),Khuggingfaces.cv(),Parm<Obj>(inParams,2).cv(),Koptions.cv(),Parm<Obj>(inParams,3).cv(),Kevent.cv(),Parm<Obj>(inParams,4).cv()},10,1471)) goto _0;
			Obj t4;
			if (g->Call(ctx,(PCV[]){t4.cv()},0,1470)) goto _0;
			Variant t5;
			if (g->GetMember(ctx,t4.cv(),K__onTCP.cv(),t5.cv())) goto _0;
			Obj t6;
			Obj t7;
			if (!g->GetValue(ctx,(PCV[]){t7.cv(),t5.cv(),nullptr})) goto _0;
			proc_MAIN(glob,ctx,2,3,(PCV[]){t3.cv(),t7.cv(),t6.cv()},nullptr);
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
		}
_0:
_1:
;
	}

}
extern Txt K_2EONNX;
extern Txt K__main;
extern Txt K__server;
extern Txt Kchat_2Ecompletion;
extern Txt Kembedding;
extern Txt Kevent;
extern Txt Kfolder;
extern Txt Khuggingface;
extern Txt Khuggingfaces;
extern Txt KisRunning;
extern Txt Klength;
extern Txt Knew;
extern Txt Kworker;
extern Txt Kworkers;
extern Txt k3Rlg958VQNg;
extern Txt kMxqcx3rAi_c;
extern Txt kPIGCCwt8ytc;
extern Txt kuIWVVuD86eI;
extern unsigned char D_proc_ONNX_3Aconstructor[];
void proc_ONNX_3Aconstructor( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc_ONNX_3Aconstructor);
	if (!ctx->doingAbort && c.f.fLine==0) {
		Variant lembeddings;
		Variant lchat;
		Txt lURL;
		Variant lfolder;
		Obj lhomeFolder;
		Obj lONNX;
		c.f.fLine=2;
		if (g->Call(ctx,(PCV[]){nullptr},0,1705)) goto _0;
		{
			Obj t0;
			c.f.fLine=5;
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
		c.f.fLine=7;
		{
			Variant t7;
			if (g->Call(ctx,(PCV[]){t7.cv(),lONNX.cv(),KisRunning.cv(),Parm<Long>(inParams,1).cv()},3,1498)) goto _0;
			g->Check(ctx);
			Bool t8;
			if (!g->GetValue(ctx,(PCV[]){t8.cv(),t7.cv(),nullptr})) goto _0;
			Bool t9;
			t9=!(t8.get());
			if (!(t9.get())) goto _2;
		}
		{
			Obj t10;
			c.f.fLine=10;
			if (g->Call(ctx,(PCV[]){t10.cv(),Long(118).cv()},1,1567)) goto _0;
			g->Check(ctx);
			Variant t11;
			if (g->Call(ctx,(PCV[]){t11.cv(),t10.cv(),Kfolder.cv(),K_2EONNX.cv()},3,1498)) goto _0;
			Obj t12;
			if (!g->GetValue(ctx,(PCV[]){t12.cv(),t11.cv(),nullptr})) goto _0;
			lhomeFolder=t12.get();
		}
		{
			Bool t13;
			t13=Parm<Obj>(inParams,2).isNull();
			Bool t14;
			t14=t13.get();
			if (t13.get()) goto _3;
			{
				{
					Obj t15;
					c.f.fLine=12;
					if (g->Call(ctx,(PCV[]){t15.cv()},0,1710)) goto _0;
					Variant t16;
					if (g->Call(ctx,(PCV[]){t16.cv(),t15.cv(),Kevent.cv(),Long(56).cv()},3,1496)) goto _0;
					g->Check(ctx);
					Variant t17;
					if (g->Call(ctx,(PCV[]){t17.cv(),t16.cv(),Khuggingfaces.cv(),Long(56).cv()},3,1496)) goto _0;
					Obj t18;
					if (!g->GetValue(ctx,(PCV[]){t18.cv(),t17.cv(),nullptr})) goto _0;
					Bool t19;
					if (g->Call(ctx,(PCV[]){t19.cv(),Parm<Obj>(inParams,2).cv(),t18.cv()},2,1731)) goto _0;
					Bool t20;
					t20=t19.get();
					Bool t21;
					t21=!(t20.get());
					t14=t21.get();
				}
			}
_3:
			Bool t22;
			t22=t14.get();
			if (t14.get()) goto _4;
			{
				{
					Variant t23;
					if (g->Call(ctx,(PCV[]){t23.cv(),Parm<Obj>(inParams,2).cv(),Khuggingfaces.cv(),Long(57).cv()},3,1496)) goto _0;
					Variant t24;
					if (g->Call(ctx,(PCV[]){t24.cv(),t23.cv(),Klength.cv(),Long(4).cv()},3,1496)) goto _0;
					Bool t25;
					if (g->OperationOnAny(ctx,6,t24.cv(),Num(0).cv(),t25.cv())) goto _0;
					t22=t25.get();
				}
			}
_4:
			if (!(t22.get())) goto _5;
		}
		{
			Variant t26;
			c.f.fLine=13;
			if (g->Call(ctx,(PCV[]){t26.cv(),lhomeFolder.cv(),Kfolder.cv(),k3Rlg958VQNg.cv()},3,1498)) goto _0;
			g->Check(ctx);
			if (!g->SetValue(ctx,(PCV[]){t26.cv(),lfolder.cv(),nullptr})) goto _0;
		}
		lURL=kPIGCCwt8ytc.get();
		{
			Obj t27;
			c.f.fLine=15;
			if (g->Call(ctx,(PCV[]){t27.cv()},0,1710)) goto _0;
			Variant t28;
			if (g->Call(ctx,(PCV[]){t28.cv(),t27.cv(),Kevent.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t29;
			if (g->Call(ctx,(PCV[]){t29.cv(),t28.cv(),Khuggingface.cv(),Long(56).cv()},3,1496)) goto _0;
			Variant t30;
			if (!g->GetValue(ctx,(PCV[]){t30.cv(),lfolder.cv(),nullptr})) goto _0;
			Variant t31;
			if (g->Call(ctx,(PCV[]){t31.cv(),t29.cv(),Knew.cv(),t30.cv(),lURL.cv(),Kchat_2Ecompletion.cv()},5,1498)) goto _0;
			if (!g->SetValue(ctx,(PCV[]){t31.cv(),lchat.cv(),nullptr})) goto _0;
		}
		{
			Variant t32;
			c.f.fLine=16;
			if (g->Call(ctx,(PCV[]){t32.cv(),lhomeFolder.cv(),Kfolder.cv(),kMxqcx3rAi_c.cv()},3,1498)) goto _0;
			g->Check(ctx);
			if (!g->SetValue(ctx,(PCV[]){t32.cv(),lfolder.cv(),nullptr})) goto _0;
		}
		lURL=kuIWVVuD86eI.get();
		{
			Obj t33;
			c.f.fLine=18;
			if (g->Call(ctx,(PCV[]){t33.cv()},0,1710)) goto _0;
			Variant t34;
			if (g->Call(ctx,(PCV[]){t34.cv(),t33.cv(),Kevent.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t35;
			if (g->Call(ctx,(PCV[]){t35.cv(),t34.cv(),Khuggingface.cv(),Long(56).cv()},3,1496)) goto _0;
			Variant t36;
			if (!g->GetValue(ctx,(PCV[]){t36.cv(),lfolder.cv(),nullptr})) goto _0;
			Variant t37;
			if (g->Call(ctx,(PCV[]){t37.cv(),t35.cv(),Knew.cv(),t36.cv(),lURL.cv(),Kembedding.cv()},5,1498)) goto _0;
			if (!g->SetValue(ctx,(PCV[]){t37.cv(),lembeddings.cv(),nullptr})) goto _0;
		}
		{
			Obj t38;
			c.f.fLine=19;
			if (g->Call(ctx,(PCV[]){t38.cv()},0,1710)) goto _0;
			Variant t39;
			if (g->Call(ctx,(PCV[]){t39.cv(),t38.cv(),Kevent.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t40;
			if (g->Call(ctx,(PCV[]){t40.cv(),t39.cv(),Khuggingfaces.cv(),Long(56).cv()},3,1496)) goto _0;
			Variant t41;
			if (!g->GetValue(ctx,(PCV[]){t41.cv(),lembeddings.cv(),nullptr})) goto _0;
			Variant t42;
			if (!g->GetValue(ctx,(PCV[]){t42.cv(),lchat.cv(),nullptr})) goto _0;
			Col t43;
			if (g->Call(ctx,(PCV[]){t43.cv(),t42.cv(),t41.cv()},2,1472)) goto _0;
			Variant t44;
			if (g->Call(ctx,(PCV[]){t44.cv(),t40.cv(),Knew.cv(),t43.cv()},3,1498)) goto _0;
			Obj t45;
			if (!g->GetValue(ctx,(PCV[]){t45.cv(),t44.cv(),nullptr})) goto _0;
			Parm<Obj>(inParams,2)=t45.get();
		}
_5:
		{
			Bool t46;
			c.f.fLine=22;
			t46=0==Parm<Long>(inParams,1).get();
			Bool t47;
			t47=t46.get();
			if (t46.get()) goto _6;
			{
				t47=0>Parm<Long>(inParams,1).get();
			}
_6:
			Bool t49;
			t49=t47.get();
			if (t47.get()) goto _7;
			{
				t49=65535<Parm<Long>(inParams,1).get();
			}
_7:
			if (!(t49.get())) goto _8;
		}
		c.f.fLine=23;
		Parm<Long>(inParams,1)=8080;
_8:
		{
			Obj t51;
			c.f.fLine=26;
			if (g->Call(ctx,(PCV[]){t51.cv()},0,1470)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t51.cv(),K__main.cv(),Parm<Long>(inParams,1).cv(),Parm<Obj>(inParams,2).cv(),Parm<Obj>(inParams,3).cv(),Parm<Obj>(inParams,4).cv()},6,1500)) goto _0;
			g->Check(ctx);
		}
_2:
_0:
_1:
;
	}

}
