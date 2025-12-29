extern Txt Kcontroller;
extern Txt Kworker;
extern unsigned char D_proc___ONNX_2Eget_20worker[];
void proc___ONNX_2Eget_20worker( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___ONNX_2Eget_20worker);
	if (!ctx->doingAbort && c.f.fLine==0) {
		new ( outResult) Obj();
		{
			Obj t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			Variant t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv(),Kcontroller.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t2;
			if (g->Call(ctx,(PCV[]){t2.cv(),t1.cv(),Kworker.cv(),Long(56).cv()},3,1496)) goto _0;
			Obj t3;
			if (!g->GetValue(ctx,(PCV[]){t3.cv(),t2.cv(),nullptr})) goto _0;
			Res<Obj>(outResult)=t3.get();
		}
		asm volatile("");
		goto _0;
_0:
_1:
;
	}

}
extern unsigned char D_proc___ONNX_2Ebind[];
void proc___ONNX_2Ebind( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___ONNX_2Ebind);
	if (!ctx->doingAbort && c.f.fLine==0) {
		Obj l__4D__auto__iter__0;
		Txt lproperty;
		new ( outResult) Obj();
		c.f.fLine=3;
		{
			Ref t0;
			t0.setLocalRef(ctx,lproperty.cv());
			Obj t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv(),Parm<Col>(inParams,2).cv()},2,1795)) goto _0;
			l__4D__auto__iter__0=t1.get();
		}
_2:
		{
			Bool t2;
			if (g->Call(ctx,(PCV[]){t2.cv(),l__4D__auto__iter__0.cv()},1,1796)) goto _0;
			g->Check(ctx);
			if (!(t2.get())) goto _3;
		}
		{
			Obj t3;
			c.f.fLine=4;
			if (g->Call(ctx,(PCV[]){t3.cv()},0,1470)) goto _0;
			Variant t4;
			if (g->GetMember(ctx,Parm<Obj>(inParams,1).cv(),lproperty.cv(),t4.cv())) goto _0;
			if (g->SetMember(ctx,t3.cv(),lproperty.cv(),t4.cv())) goto _0;
		}
		asm volatile("");
		goto _2;
_3:
		{
			Obj t5;
			l__4D__auto__iter__0=t5.get();
		}
		{
			Obj t6;
			c.f.fLine=7;
			if (g->Call(ctx,(PCV[]){t6.cv()},0,1470)) goto _0;
			Res<Obj>(outResult)=t6.get();
		}
		asm volatile("");
		goto _0;
_0:
_1:
;
	}

}
extern Txt Kcontroller;
extern Txt Kterminate;
extern unsigned char D_proc___ONNX_2Eterminate[];
void proc___ONNX_2Eterminate( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___ONNX_2Eterminate);
	if (!ctx->doingAbort && c.f.fLine==0) {
		{
			Obj t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			Variant t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv(),Kcontroller.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,t1.cv(),Kterminate.cv()},2,1500)) goto _0;
		}
_0:
_1:
;
	}

}
extern Txt Kname;
extern Txt Ksuperclass;
extern Txt kHA1hjWGXwj4;
extern unsigned char D_proc___ONNX_3Aconstructor[];
void proc___ONNX_3Aconstructor( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___ONNX_3Aconstructor);
	if (!ctx->doingAbort && c.f.fLine==0) {
		Obj lsuperclass;
		Obj lcontroller;
		c.f.fLine=4;
		{
			Variant t0;
			if (g->Call(ctx,(PCV[]){t0.cv(),Parm<Obj>(inParams,2).cv(),Ksuperclass.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Obj t1;
			if (!g->GetValue(ctx,(PCV[]){t1.cv(),t0.cv(),nullptr})) goto _0;
			lsuperclass=t1.get();
		}
		{
			Obj t2;
			c.f.fLine=5;
			if (g->Call(ctx,(PCV[]){t2.cv()},0,1710)) goto _0;
			Variant t3;
			if (g->Call(ctx,(PCV[]){t3.cv(),t2.cv(),kHA1hjWGXwj4.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Obj t4;
			if (!g->GetValue(ctx,(PCV[]){t4.cv(),t3.cv(),nullptr})) goto _0;
			lcontroller=t4.get();
		}
_2:
		{
			Bool t5;
			t5=!lsuperclass.isNull();
			if (!(t5.get())) goto _3;
		}
		{
			Variant t6;
			c.f.fLine=8;
			if (g->Call(ctx,(PCV[]){t6.cv(),lsuperclass.cv(),Kname.cv(),Long(11).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t7;
			if (g->Call(ctx,(PCV[]){t7.cv(),lcontroller.cv(),Kname.cv(),Long(11).cv()},3,1496)) goto _0;
			Bool t8;
			if (g->OperationOnAny(ctx,6,t6.cv(),t7.cv(),t8.cv())) goto _0;
			if (!(t8.get())) goto _4;
		}
		c.f.fLine=9;
		lcontroller=Parm<Obj>(inParams,2).get();
		asm volatile("");
		goto _3;
_4:
		{
			Variant t9;
			c.f.fLine=12;
			if (g->Call(ctx,(PCV[]){t9.cv(),lsuperclass.cv(),Ksuperclass.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Obj t10;
			if (!g->GetValue(ctx,(PCV[]){t10.cv(),t9.cv(),nullptr})) goto _0;
			lsuperclass=t10.get();
		}
		asm volatile("");
		goto _2;
_3:
		c.f.fLine=15;
		if (g->Call(ctx,(PCV[]){nullptr,Parm<Txt>(inParams,1).cv(),lcontroller.cv()},2,1705)) goto _0;
_0:
_1:
;
	}

}
