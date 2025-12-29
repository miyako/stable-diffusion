extern Txt KFunction;
extern Txt Kcall;
extern Txt Kinstance;
extern Txt KonTerminate;
extern unsigned char D_proc___ONNX__Controller_2EonTerminate[];
void proc___ONNX__Controller_2EonTerminate( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___ONNX__Controller_2EonTerminate);
	if (!ctx->doingAbort && c.f.fLine==0) {
		Obj linstance;
		{
			Obj t0;
			c.f.fLine=3;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			Variant t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv(),Kinstance.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Obj t2;
			if (!g->GetValue(ctx,(PCV[]){t2.cv(),t1.cv(),nullptr})) goto _0;
			linstance=t2.get();
		}
		{
			Variant t3;
			c.f.fLine=5;
			if (g->Call(ctx,(PCV[]){t3.cv(),linstance.cv(),KonTerminate.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Bool t4;
			if (g->OperationOnAny(ctx,7,t3.cv(),Value_null().cv(),t4.cv())) goto _0;
			Bool t5;
			t5=t4.get();
			if (!(t4.get())) goto _2;
			{
				{
					Variant t6;
					if (g->Call(ctx,(PCV[]){t6.cv(),linstance.cv(),KonTerminate.cv(),Long(56).cv()},3,1496)) goto _0;
					Obj t7;
					if (g->Call(ctx,(PCV[]){t7.cv()},0,1709)) goto _0;
					Variant t8;
					if (g->Call(ctx,(PCV[]){t8.cv(),t7.cv(),KFunction.cv(),Long(56).cv()},3,1496)) goto _0;
					Obj t9;
					if (!g->GetValue(ctx,(PCV[]){t9.cv(),t8.cv(),nullptr})) goto _0;
					Obj t10;
					if (!g->GetValue(ctx,(PCV[]){t10.cv(),t6.cv(),nullptr})) goto _0;
					Bool t11;
					if (g->Call(ctx,(PCV[]){t11.cv(),t10.cv(),t9.cv()},2,1731)) goto _0;
					t5=t11.get();
				}
			}
_2:
			if (!(t5.get())) goto _3;
		}
		{
			Variant t12;
			c.f.fLine=6;
			if (g->Call(ctx,(PCV[]){t12.cv(),linstance.cv(),KonTerminate.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Obj t13;
			if (g->Call(ctx,(PCV[]){t13.cv()},0,1470)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t12.cv(),Kcall.cv(),t13.cv(),Parm<Obj>(inParams,1).cv(),Parm<Obj>(inParams,2).cv()},5,1500)) goto _0;
		}
_3:
_0:
_1:
;
	}

}
extern unsigned char D_proc___ONNX__Controller_3Aconstructor[];
void proc___ONNX__Controller_3Aconstructor( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___ONNX__Controller_3Aconstructor);
	if (!ctx->doingAbort && c.f.fLine==0) {
		c.f.fLine=2;
		if (g->Call(ctx,(PCV[]){nullptr,Parm<Obj>(inParams,1).cv()},1,1705)) goto _0;
_0:
_1:
;
	}

}
