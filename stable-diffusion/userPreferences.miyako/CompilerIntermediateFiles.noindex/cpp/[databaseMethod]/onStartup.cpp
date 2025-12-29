extern Txt K;
extern Txt KONNX;
extern Txt K_2EONNX;
extern Txt Kchat_2Ecompletion;
extern Txt Kembedding;
extern Txt Kevent;
extern Txt Kfolder;
extern Txt Khuggingface;
extern Txt Khuggingfaces;
extern Txt Knew;
extern Txt KonData;
extern Txt KonError;
extern Txt KonResponse;
extern Txt KonSuccess;
extern Txt KonTerminate;
extern Txt kMxqcx3rAi_c;
extern Txt kPIGCCwt8ytc;
extern Txt krRd2tRnVBsk;
extern Txt kuIWVVuD86eI;
extern Txt kz6i_FIwZAJE;
extern unsigned char D_db_1[];
void db_1( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_db_1);
	if (!ctx->doingAbort && c.f.fLine==0) {
		Obj lONNX;
		Variant lembeddings;
		Obj lfile;
		Obj loptions;
		Obj lhuggingfaces;
		Variant lchat;
		Txt lpath;
		Variant lfolder;
		Obj levent;
		Long lport;
		Txt lURL;
		Obj lhomeFolder;
		if (!(Bool(0).get())) goto _2;
		{
			Obj t0;
			c.f.fLine=4;
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
		asm volatile("");
		goto _3;
_2:
		{
			Obj t4;
			c.f.fLine=7;
			if (g->Call(ctx,(PCV[]){t4.cv(),Long(118).cv()},1,1567)) goto _0;
			g->Check(ctx);
			Variant t5;
			if (g->Call(ctx,(PCV[]){t5.cv(),t4.cv(),Kfolder.cv(),K_2EONNX.cv()},3,1498)) goto _0;
			Obj t6;
			if (!g->GetValue(ctx,(PCV[]){t6.cv(),t5.cv(),nullptr})) goto _0;
			lhomeFolder=t6.get();
		}
		{
			Obj t7;
			c.f.fLine=13;
			if (g->Call(ctx,(PCV[]){t7.cv()},0,1710)) goto _0;
			Variant t8;
			if (g->Call(ctx,(PCV[]){t8.cv(),t7.cv(),Kevent.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t9;
			if (g->Call(ctx,(PCV[]){t9.cv(),t8.cv(),Kevent.cv(),Long(56).cv()},3,1496)) goto _0;
			Variant t10;
			if (g->Call(ctx,(PCV[]){t10.cv(),t9.cv(),Knew.cv()},2,1498)) goto _0;
			Obj t11;
			if (!g->GetValue(ctx,(PCV[]){t11.cv(),t10.cv(),nullptr})) goto _0;
			levent=t11.get();
		}
		asm volatile("");
		goto _4;
_4:
		{
			Obj t15;
			c.f.fLine=22;
			if (g->Call(ctx,(PCV[]){t15.cv(),Long(0).cv(),(CV*)-1,nullptr,Long(1).cv(),Long(2).cv()},5,1597)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,levent.cv(),KonError.cv(),t15.cv(),Long(56).cv()},4,1497)) goto _0;
		}
		asm volatile("");
		goto _5;
_5:
		{
			Obj t22;
			c.f.fLine=23;
			if (g->Call(ctx,(PCV[]){t22.cv(),Long(0).cv(),(CV*)-1,nullptr,Long(2).cv(),Long(2).cv()},5,1597)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,levent.cv(),KonSuccess.cv(),t22.cv(),Long(56).cv()},4,1497)) goto _0;
		}
		asm volatile("");
		goto _6;
_6:
		{
			Obj t38;
			c.f.fLine=24;
			if (g->Call(ctx,(PCV[]){t38.cv(),Long(0).cv(),(CV*)-1,nullptr,Long(3).cv(),Long(0).cv()},5,1597)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,levent.cv(),KonData.cv(),t38.cv(),Long(56).cv()},4,1497)) goto _0;
		}
		asm volatile("");
		goto _7;
_7:
		{
			Obj t54;
			c.f.fLine=25;
			if (g->Call(ctx,(PCV[]){t54.cv(),Long(0).cv(),(CV*)-1,nullptr,Long(4).cv(),Long(0).cv()},5,1597)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,levent.cv(),KonData.cv(),t54.cv(),Long(56).cv()},4,1497)) goto _0;
		}
		asm volatile("");
		goto _8;
_8:
		{
			Obj t60;
			c.f.fLine=26;
			if (g->Call(ctx,(PCV[]){t60.cv(),Long(0).cv(),(CV*)-1,nullptr,Long(5).cv(),Long(0).cv()},5,1597)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,levent.cv(),KonResponse.cv(),t60.cv(),Long(56).cv()},4,1497)) goto _0;
		}
		asm volatile("");
		goto _9;
_9:
		{
			Obj t66;
			c.f.fLine=27;
			if (g->Call(ctx,(PCV[]){t66.cv(),Long(0).cv(),(CV*)-1,nullptr,Long(6).cv(),Long(0).cv()},5,1597)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,levent.cv(),KonResponse.cv(),t66.cv(),Long(56).cv()},4,1497)) goto _0;
		}
		asm volatile("");
		goto _10;
_10:
		{
			Obj t72;
			c.f.fLine=28;
			if (g->Call(ctx,(PCV[]){t72.cv(),Long(0).cv(),(CV*)-1,nullptr,Long(7).cv(),Long(1).cv()},5,1597)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,levent.cv(),KonTerminate.cv(),t72.cv(),Long(56).cv()},4,1497)) goto _0;
		}
		lport=8088;
		{
			Variant t73;
			c.f.fLine=32;
			if (g->Call(ctx,(PCV[]){t73.cv(),lhomeFolder.cv(),Kfolder.cv(),kPIGCCwt8ytc.cv()},3,1498)) goto _0;
			g->Check(ctx);
			if (!g->SetValue(ctx,(PCV[]){t73.cv(),lfolder.cv(),nullptr})) goto _0;
		}
		lpath=krRd2tRnVBsk.get();
		lURL=kz6i_FIwZAJE.get();
		{
			Obj t74;
			c.f.fLine=35;
			if (g->Call(ctx,(PCV[]){t74.cv()},0,1710)) goto _0;
			Variant t75;
			if (g->Call(ctx,(PCV[]){t75.cv(),t74.cv(),Kevent.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t76;
			if (g->Call(ctx,(PCV[]){t76.cv(),t75.cv(),Khuggingface.cv(),Long(56).cv()},3,1496)) goto _0;
			Variant t77;
			if (!g->GetValue(ctx,(PCV[]){t77.cv(),lfolder.cv(),nullptr})) goto _0;
			Variant t78;
			if (g->Call(ctx,(PCV[]){t78.cv(),t76.cv(),Knew.cv(),t77.cv(),lURL.cv(),lpath.cv(),Kchat_2Ecompletion.cv()},6,1498)) goto _0;
			if (!g->SetValue(ctx,(PCV[]){t78.cv(),lchat.cv(),nullptr})) goto _0;
		}
		{
			Variant t79;
			c.f.fLine=37;
			if (g->Call(ctx,(PCV[]){t79.cv(),lhomeFolder.cv(),Kfolder.cv(),kMxqcx3rAi_c.cv()},3,1498)) goto _0;
			g->Check(ctx);
			if (!g->SetValue(ctx,(PCV[]){t79.cv(),lfolder.cv(),nullptr})) goto _0;
		}
		lpath=K.get();
		lURL=kuIWVVuD86eI.get();
		{
			Obj t80;
			c.f.fLine=40;
			if (g->Call(ctx,(PCV[]){t80.cv()},0,1710)) goto _0;
			Variant t81;
			if (g->Call(ctx,(PCV[]){t81.cv(),t80.cv(),Kevent.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t82;
			if (g->Call(ctx,(PCV[]){t82.cv(),t81.cv(),Khuggingface.cv(),Long(56).cv()},3,1496)) goto _0;
			Variant t83;
			if (!g->GetValue(ctx,(PCV[]){t83.cv(),lfolder.cv(),nullptr})) goto _0;
			Variant t84;
			if (g->Call(ctx,(PCV[]){t84.cv(),t82.cv(),Knew.cv(),t83.cv(),lURL.cv(),lpath.cv(),Kembedding.cv()},6,1498)) goto _0;
			if (!g->SetValue(ctx,(PCV[]){t84.cv(),lembeddings.cv(),nullptr})) goto _0;
		}
		{
			Obj t85;
			c.f.fLine=42;
			if (g->Call(ctx,(PCV[]){t85.cv()},0,1471)) goto _0;
			g->Check(ctx);
			loptions=t85.get();
		}
		{
			Obj t86;
			c.f.fLine=44;
			if (g->Call(ctx,(PCV[]){t86.cv()},0,1710)) goto _0;
			Variant t87;
			if (g->Call(ctx,(PCV[]){t87.cv(),t86.cv(),Kevent.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t88;
			if (g->Call(ctx,(PCV[]){t88.cv(),t87.cv(),Khuggingfaces.cv(),Long(56).cv()},3,1496)) goto _0;
			Variant t89;
			if (!g->GetValue(ctx,(PCV[]){t89.cv(),lembeddings.cv(),nullptr})) goto _0;
			Variant t90;
			if (!g->GetValue(ctx,(PCV[]){t90.cv(),lchat.cv(),nullptr})) goto _0;
			Col t91;
			if (g->Call(ctx,(PCV[]){t91.cv(),t90.cv(),t89.cv()},2,1472)) goto _0;
			Variant t92;
			if (g->Call(ctx,(PCV[]){t92.cv(),t88.cv(),Knew.cv(),t91.cv()},3,1498)) goto _0;
			Obj t93;
			if (!g->GetValue(ctx,(PCV[]){t93.cv(),t92.cv(),nullptr})) goto _0;
			lhuggingfaces=t93.get();
		}
		{
			Obj t94;
			c.f.fLine=46;
			if (g->Call(ctx,(PCV[]){t94.cv()},0,1710)) goto _0;
			Variant t95;
			if (g->Call(ctx,(PCV[]){t95.cv(),t94.cv(),KONNX.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t96;
			if (g->Call(ctx,(PCV[]){t96.cv(),t95.cv(),Knew.cv(),lport.cv(),lhuggingfaces.cv(),loptions.cv(),levent.cv()},6,1498)) goto _0;
			Obj t97;
			if (!g->GetValue(ctx,(PCV[]){t97.cv(),t96.cv(),nullptr})) goto _0;
			lONNX=t97.get();
		}
_3:
_0:
_1:
;
	}

}
