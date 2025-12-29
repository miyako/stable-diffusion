extern Txt K;
extern Txt KFile;
extern Txt KFolder;
extern Txt K_20;
extern Txt K_20_2D_2D;
extern Txt K_20_2De_20;
extern Txt K_20_2Dh_20;
extern Txt K_20_2Dm_20;
extern Txt K_20_2Dp_20;
extern Txt K_20_2Ds_20;
extern Txt K_2D;
extern Txt K__;
extern Txt Kbind;
extern Txt Kcontroller;
extern Txt Ke;
extern Txt Kescape;
extern Txt KexecutablePath;
extern Txt Kexecute;
extern Txt Kexists;
extern Txt Kexpand;
extern Txt Kfile;
extern Txt Kh;
extern Txt Khost;
extern Txt Ki;
extern Txt Kincludes;
extern Txt Kkey;
extern Txt Km;
extern Txt Kmodel_2Eonnx;
extern Txt Ko;
extern Txt KonTerminate;
extern Txt Kp;
extern Txt Kpath;
extern Txt Kport;
extern Txt Kvalue;
extern Txt Kworker;
extern Txt k5pd6qQIgcLQ;
extern Txt kcVtzG12P014;
extern unsigned char D_proc___server_2Estart[];
void proc___server_2Estart( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___server_2Estart);
	if (!ctx->doingAbort && c.f.fLine==0) {
		Obj l__4D__auto__iter__0;
		Txt lkey;
		Long lvalueType;
		Obj larg;
		Txt lcommand;
		new ( outResult) Obj();
		{
			Obj t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			Col t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),KonTerminate.cv()},1,1472)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,t0.cv(),Kbind.cv(),Parm<Obj>(inParams,1).cv(),t1.cv()},4,1500)) goto _0;
		}
		{
			Obj t2;
			c.f.fLine=5;
			if (g->Call(ctx,(PCV[]){t2.cv()},0,1470)) goto _0;
			Obj t3;
			if (g->Call(ctx,(PCV[]){t3.cv()},0,1470)) goto _0;
			Variant t4;
			if (g->Call(ctx,(PCV[]){t4.cv(),t3.cv(),KexecutablePath.cv(),Long(11).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t5;
			if (g->Call(ctx,(PCV[]){t5.cv(),t2.cv(),Kescape.cv(),t4.cv()},3,1498)) goto _0;
			Txt t6;
			if (!g->GetValue(ctx,(PCV[]){t6.cv(),t5.cv(),nullptr})) goto _0;
			lcommand=t6.get();
		}
		g->AddString(lcommand.get(),K_20_2Ds_20.get(),lcommand.get());
		{
			Variant t8;
			c.f.fLine=9;
			if (g->GetMember(ctx,Parm<Obj>(inParams,1).cv(),k5pd6qQIgcLQ.cv(),t8.cv())) goto _0;
			Long t9;
			if (g->Call(ctx,(PCV[]){t9.cv(),t8.cv()},1,1509)) goto _0;
			Bool t10;
			t10=38==t9.get();
			Bool t11;
			t11=t10.get();
			if (!(t10.get())) goto _2;
			{
				{
					Variant t12;
					if (g->GetMember(ctx,Parm<Obj>(inParams,1).cv(),k5pd6qQIgcLQ.cv(),t12.cv())) goto _0;
					Obj t13;
					if (g->Call(ctx,(PCV[]){t13.cv()},0,1709)) goto _0;
					Variant t14;
					if (g->Call(ctx,(PCV[]){t14.cv(),t13.cv(),KFolder.cv(),Long(56).cv()},3,1496)) goto _0;
					g->Check(ctx);
					Obj t15;
					if (!g->GetValue(ctx,(PCV[]){t15.cv(),t14.cv(),nullptr})) goto _0;
					Obj t16;
					if (!g->GetValue(ctx,(PCV[]){t16.cv(),t12.cv(),nullptr})) goto _0;
					Bool t17;
					if (g->Call(ctx,(PCV[]){t17.cv(),t16.cv(),t15.cv()},2,1731)) goto _0;
					t11=t17.get();
				}
			}
_2:
			Variant t18;
			if (!g->SetValue(ctx,(PCV[]){t11.cv(),t18.cv(),nullptr})) goto _0;
			if (!(t11.get())) goto _3;
			{
				{
					Variant t19;
					if (g->GetMember(ctx,Parm<Obj>(inParams,1).cv(),k5pd6qQIgcLQ.cv(),t19.cv())) goto _0;
					if (g->GetMember(ctx,t19.cv(),Kexists.cv(),t18.cv())) goto _0;
				}
			}
_3:
			Bool t21;
			if (!g->GetValue(ctx,(PCV[]){t21.cv(),t18.cv(),nullptr})) goto _0;
			if (!(t21.get())) goto _4;
		}
		g->AddString(lcommand.get(),K_20_2Dm_20.get(),lcommand.get());
		{
			Obj t23;
			c.f.fLine=11;
			if (g->Call(ctx,(PCV[]){t23.cv()},0,1470)) goto _0;
			Obj t24;
			if (g->Call(ctx,(PCV[]){t24.cv()},0,1470)) goto _0;
			Variant t25;
			if (g->GetMember(ctx,Parm<Obj>(inParams,1).cv(),k5pd6qQIgcLQ.cv(),t25.cv())) goto _0;
			Variant t26;
			if (g->Call(ctx,(PCV[]){t26.cv(),t24.cv(),Kexpand.cv(),t25.cv()},3,1498)) goto _0;
			g->Check(ctx);
			Variant t27;
			if (g->GetMember(ctx,t26.cv(),Kpath.cv(),t27.cv())) goto _0;
			Variant t28;
			if (g->Call(ctx,(PCV[]){t28.cv(),t23.cv(),Kescape.cv(),t27.cv()},3,1498)) goto _0;
			Variant t29;
			if (g->OperationOnAny(ctx,0,lcommand.cv(),t28.cv(),t29.cv())) goto _0;
			Txt t30;
			if (!g->GetValue(ctx,(PCV[]){t30.cv(),t29.cv(),nullptr})) goto _0;
			lcommand=t30.get();
		}
		g->AddString(lcommand.get(),K_20.get(),lcommand.get());
_4:
		{
			Variant t32;
			c.f.fLine=15;
			if (g->GetMember(ctx,Parm<Obj>(inParams,1).cv(),kcVtzG12P014.cv(),t32.cv())) goto _0;
			Long t33;
			if (g->Call(ctx,(PCV[]){t33.cv(),t32.cv()},1,1509)) goto _0;
			Bool t34;
			t34=38==t33.get();
			Bool t35;
			t35=t34.get();
			if (!(t34.get())) goto _5;
			{
				{
					Variant t36;
					if (g->GetMember(ctx,Parm<Obj>(inParams,1).cv(),kcVtzG12P014.cv(),t36.cv())) goto _0;
					Obj t37;
					if (g->Call(ctx,(PCV[]){t37.cv()},0,1709)) goto _0;
					Variant t38;
					if (g->Call(ctx,(PCV[]){t38.cv(),t37.cv(),KFolder.cv(),Long(56).cv()},3,1496)) goto _0;
					g->Check(ctx);
					Obj t39;
					if (!g->GetValue(ctx,(PCV[]){t39.cv(),t38.cv(),nullptr})) goto _0;
					Obj t40;
					if (!g->GetValue(ctx,(PCV[]){t40.cv(),t36.cv(),nullptr})) goto _0;
					Bool t41;
					if (g->Call(ctx,(PCV[]){t41.cv(),t40.cv(),t39.cv()},2,1731)) goto _0;
					t35=t41.get();
				}
			}
_5:
			Variant t42;
			if (!g->SetValue(ctx,(PCV[]){t35.cv(),t42.cv(),nullptr})) goto _0;
			if (!(t35.get())) goto _6;
			{
				{
					Variant t43;
					if (g->GetMember(ctx,Parm<Obj>(inParams,1).cv(),kcVtzG12P014.cv(),t43.cv())) goto _0;
					if (g->GetMember(ctx,t43.cv(),Kexists.cv(),t42.cv())) goto _0;
				}
			}
_6:
			Bool t45;
			if (!g->GetValue(ctx,(PCV[]){t45.cv(),t42.cv(),nullptr})) goto _0;
			if (!(t45.get())) goto _7;
		}
		g->AddString(lcommand.get(),K_20_2De_20.get(),lcommand.get());
		{
			Obj t47;
			c.f.fLine=17;
			if (g->Call(ctx,(PCV[]){t47.cv()},0,1470)) goto _0;
			Obj t48;
			if (g->Call(ctx,(PCV[]){t48.cv()},0,1470)) goto _0;
			Variant t49;
			if (g->GetMember(ctx,Parm<Obj>(inParams,1).cv(),kcVtzG12P014.cv(),t49.cv())) goto _0;
			Variant t50;
			if (g->Call(ctx,(PCV[]){t50.cv(),t48.cv(),Kexpand.cv(),t49.cv()},3,1498)) goto _0;
			g->Check(ctx);
			Variant t51;
			if (g->Call(ctx,(PCV[]){t51.cv(),t50.cv(),Kfile.cv(),Kmodel_2Eonnx.cv()},3,1498)) goto _0;
			Variant t52;
			if (g->GetMember(ctx,t51.cv(),Kpath.cv(),t52.cv())) goto _0;
			Variant t53;
			if (g->Call(ctx,(PCV[]){t53.cv(),t47.cv(),Kescape.cv(),t52.cv()},3,1498)) goto _0;
			Variant t54;
			if (g->OperationOnAny(ctx,0,lcommand.cv(),t53.cv(),t54.cv())) goto _0;
			Txt t55;
			if (!g->GetValue(ctx,(PCV[]){t55.cv(),t54.cv(),nullptr})) goto _0;
			lcommand=t55.get();
		}
		g->AddString(lcommand.get(),K_20.get(),lcommand.get());
_7:
		g->AddString(lcommand.get(),K_20_2Dp_20.get(),lcommand.get());
		{
			Variant t58;
			c.f.fLine=22;
			if (g->GetMember(ctx,Parm<Obj>(inParams,1).cv(),Kport.cv(),t58.cv())) goto _0;
			Txt t59;
			if (g->Call(ctx,(PCV[]){t59.cv(),t58.cv()},1,10)) goto _0;
			g->AddString(lcommand.get(),t59.get(),lcommand.get());
		}
		g->AddString(lcommand.get(),K_20.get(),lcommand.get());
		{
			Variant t62;
			c.f.fLine=25;
			if (g->GetMember(ctx,Parm<Obj>(inParams,1).cv(),Khost.cv(),t62.cv())) goto _0;
			Long t63;
			if (g->Call(ctx,(PCV[]){t63.cv(),t62.cv()},1,1509)) goto _0;
			Bool t64;
			t64=2==t63.get();
			Bool t65;
			t65=t64.get();
			if (!(t64.get())) goto _8;
			{
				{
					Variant t66;
					if (g->GetMember(ctx,Parm<Obj>(inParams,1).cv(),Khost.cv(),t66.cv())) goto _0;
					Bool t67;
					if (g->OperationOnAny(ctx,7,t66.cv(),K.cv(),t67.cv())) goto _0;
					t65=t67.get();
				}
			}
_8:
			if (!(t65.get())) goto _9;
		}
		g->AddString(lcommand.get(),K_20_2Dh_20.get(),lcommand.get());
		{
			Variant t69;
			c.f.fLine=27;
			if (g->GetMember(ctx,Parm<Obj>(inParams,1).cv(),Khost.cv(),t69.cv())) goto _0;
			Variant t70;
			if (g->OperationOnAny(ctx,0,lcommand.cv(),t69.cv(),t70.cv())) goto _0;
			Txt t71;
			if (!g->GetValue(ctx,(PCV[]){t71.cv(),t70.cv(),nullptr})) goto _0;
			lcommand=t71.get();
		}
		g->AddString(lcommand.get(),K_20.get(),lcommand.get());
_9:
		c.f.fLine=35;
		{
			Col t73;
			if (g->Call(ctx,(PCV[]){t73.cv(),Parm<Obj>(inParams,1).cv()},1,1720)) goto _0;
			g->Check(ctx);
			Ref t74;
			t74.setLocalRef(ctx,larg.cv());
			Obj t75;
			if (g->Call(ctx,(PCV[]){t75.cv(),t74.cv(),t73.cv()},2,1795)) goto _0;
			l__4D__auto__iter__0=t75.get();
		}
_10:
		{
			Bool t76;
			if (g->Call(ctx,(PCV[]){t76.cv(),l__4D__auto__iter__0.cv()},1,1796)) goto _0;
			if (!(t76.get())) goto _11;
		}
		{
			Col t77;
			c.f.fLine=37;
			if (g->Call(ctx,(PCV[]){t77.cv(),Km.cv(),Ke.cv(),Kh.cv(),Kp.cv(),Ki.cv(),Ko.cv(),Kport.cv()},7,1472)) goto _0;
			g->Check(ctx);
			Variant t78;
			if (g->GetMember(ctx,larg.cv(),Kkey.cv(),t78.cv())) goto _0;
			Variant t79;
			if (g->Call(ctx,(PCV[]){t79.cv(),t77.cv(),Kincludes.cv(),t78.cv()},3,1498)) goto _0;
			Bool t80;
			if (!g->GetValue(ctx,(PCV[]){t80.cv(),t79.cv(),nullptr})) goto _0;
			if (!(t80.get())) goto _13;
		}
		asm volatile("");
		goto _10;
		asm volatile("");
		goto _12;
_13:
_12:
		{
			Variant t81;
			c.f.fLine=40;
			if (g->GetMember(ctx,larg.cv(),Kvalue.cv(),t81.cv())) goto _0;
			Long t82;
			if (g->Call(ctx,(PCV[]){t82.cv(),t81.cv()},1,1509)) goto _0;
			lvalueType=t82.get();
		}
		{
			Variant t83;
			c.f.fLine=41;
			if (g->GetMember(ctx,larg.cv(),Kkey.cv(),t83.cv())) goto _0;
			Txt t84;
			if (!g->GetValue(ctx,(PCV[]){t84.cv(),t83.cv(),nullptr})) goto _0;
			Txt t85;
			if (g->Call(ctx,(PCV[]){t85.cv(),t84.cv(),K__.cv(),K_2D.cv(),Ref((d4_enums::optyp)3).cv()},4,233)) goto _0;
			lkey=t85.get();
		}
		if (1!=lvalueType.get()) goto _15;
		{
			Txt t87;
			g->AddString(K_20_2D_2D.get(),lkey.get(),t87.get());
			Txt t88;
			g->AddString(t87.get(),K_20.get(),t88.get());
			Variant t89;
			c.f.fLine=44;
			if (g->GetMember(ctx,larg.cv(),Kvalue.cv(),t89.cv())) goto _0;
			Txt t90;
			if (g->Call(ctx,(PCV[]){t90.cv(),t89.cv()},1,10)) goto _0;
			Txt t91;
			g->AddString(t88.get(),t90.get(),t91.get());
			Txt t92;
			g->AddString(t91.get(),K_20.get(),t92.get());
			g->AddString(lcommand.get(),t92.get(),lcommand.get());
		}
		asm volatile("");
		goto _14;
_15:
		if (2!=lvalueType.get()) goto _16;
		{
			Txt t95;
			g->AddString(K_20_2D_2D.get(),lkey.get(),t95.get());
			Txt t96;
			g->AddString(t95.get(),K_20.get(),t96.get());
			Obj t97;
			c.f.fLine=46;
			if (g->Call(ctx,(PCV[]){t97.cv()},0,1470)) goto _0;
			Variant t98;
			if (g->GetMember(ctx,larg.cv(),Kvalue.cv(),t98.cv())) goto _0;
			Variant t99;
			if (g->Call(ctx,(PCV[]){t99.cv(),t97.cv(),Kescape.cv(),t98.cv()},3,1498)) goto _0;
			g->Check(ctx);
			Variant t100;
			if (g->OperationOnAny(ctx,0,t96.cv(),t99.cv(),t100.cv())) goto _0;
			Variant t101;
			if (g->OperationOnAny(ctx,0,t100.cv(),K_20.cv(),t101.cv())) goto _0;
			Variant t102;
			if (g->OperationOnAny(ctx,0,lcommand.cv(),t101.cv(),t102.cv())) goto _0;
			Txt t103;
			if (!g->GetValue(ctx,(PCV[]){t103.cv(),t102.cv(),nullptr})) goto _0;
			lcommand=t103.get();
		}
		asm volatile("");
		goto _14;
_16:
		{
			Bool t104;
			t104=6==lvalueType.get();
			Variant t105;
			c.f.fLine=47;
			if (!g->SetValue(ctx,(PCV[]){t104.cv(),t105.cv(),nullptr})) goto _0;
			if (!(t104.get())) goto _17;
			{
				if (g->GetMember(ctx,larg.cv(),Kvalue.cv(),t105.cv())) goto _0;
			}
_17:
			Bool t107;
			if (!g->GetValue(ctx,(PCV[]){t107.cv(),t105.cv(),nullptr})) goto _0;
			if (!(t107.get())) goto _18;
		}
		{
			Txt t108;
			g->AddString(K_20_2D_2D.get(),lkey.get(),t108.get());
			Txt t109;
			g->AddString(t108.get(),K_20.get(),t109.get());
			g->AddString(lcommand.get(),t109.get(),lcommand.get());
		}
		asm volatile("");
		goto _14;
_18:
		{
			Bool t111;
			t111=38==lvalueType.get();
			Bool t112;
			t112=t111.get();
			if (!(t111.get())) goto _19;
			{
				{
					Variant t113;
					c.f.fLine=49;
					if (g->GetMember(ctx,larg.cv(),Kvalue.cv(),t113.cv())) goto _0;
					Obj t114;
					if (g->Call(ctx,(PCV[]){t114.cv()},0,1709)) goto _0;
					Variant t115;
					if (g->Call(ctx,(PCV[]){t115.cv(),t114.cv(),KFile.cv(),Long(56).cv()},3,1496)) goto _0;
					g->Check(ctx);
					Obj t116;
					if (!g->GetValue(ctx,(PCV[]){t116.cv(),t115.cv(),nullptr})) goto _0;
					Obj t117;
					if (!g->GetValue(ctx,(PCV[]){t117.cv(),t113.cv(),nullptr})) goto _0;
					Bool t118;
					if (g->Call(ctx,(PCV[]){t118.cv(),t117.cv(),t116.cv()},2,1731)) goto _0;
					t112=t118.get();
				}
			}
_19:
			if (!(t112.get())) goto _20;
		}
		{
			Txt t119;
			g->AddString(K_20_2D_2D.get(),lkey.get(),t119.get());
			Txt t120;
			g->AddString(t119.get(),K_20.get(),t120.get());
			Obj t121;
			c.f.fLine=50;
			if (g->Call(ctx,(PCV[]){t121.cv()},0,1470)) goto _0;
			Obj t122;
			if (g->Call(ctx,(PCV[]){t122.cv()},0,1470)) goto _0;
			Variant t123;
			if (g->GetMember(ctx,larg.cv(),Kvalue.cv(),t123.cv())) goto _0;
			Variant t124;
			if (g->Call(ctx,(PCV[]){t124.cv(),t122.cv(),Kexpand.cv(),t123.cv()},3,1498)) goto _0;
			g->Check(ctx);
			Variant t125;
			if (g->GetMember(ctx,t124.cv(),Kpath.cv(),t125.cv())) goto _0;
			Variant t126;
			if (g->Call(ctx,(PCV[]){t126.cv(),t121.cv(),Kescape.cv(),t125.cv()},3,1498)) goto _0;
			Variant t127;
			if (g->OperationOnAny(ctx,0,t120.cv(),t126.cv(),t127.cv())) goto _0;
			Variant t128;
			if (g->OperationOnAny(ctx,0,lcommand.cv(),t127.cv(),t128.cv())) goto _0;
			Txt t129;
			if (!g->GetValue(ctx,(PCV[]){t129.cv(),t128.cv(),nullptr})) goto _0;
			lcommand=t129.get();
		}
		asm volatile("");
		goto _14;
_20:
_14:
		asm volatile("");
		goto _10;
_11:
		{
			Obj t130;
			l__4D__auto__iter__0=t130.get();
		}
		{
			Obj t131;
			c.f.fLine=58;
			if (g->Call(ctx,(PCV[]){t131.cv()},0,1470)) goto _0;
			Variant t132;
			if (g->Call(ctx,(PCV[]){t132.cv(),t131.cv(),Kcontroller.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t133;
			if (g->Call(ctx,(PCV[]){t133.cv(),t132.cv(),Kexecute.cv(),lcommand.cv()},3,1498)) goto _0;
			Variant t134;
			if (g->Call(ctx,(PCV[]){t134.cv(),t133.cv(),Kworker.cv(),Long(56).cv()},3,1496)) goto _0;
			Obj t135;
			if (!g->GetValue(ctx,(PCV[]){t135.cv(),t134.cv(),nullptr})) goto _0;
			Res<Obj>(outResult)=t135.get();
		}
		asm volatile("");
		goto _0;
_0:
_1:
;
	}

}
extern Txt KONNX_2Dgenai;
extern unsigned char D_proc___server_3Aconstructor[];
void proc___server_3Aconstructor( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___server_3Aconstructor);
	if (!ctx->doingAbort && c.f.fLine==0) {
		c.f.fLine=2;
		if (g->Call(ctx,(PCV[]){nullptr,KONNX_2Dgenai.cv(),Parm<Obj>(inParams,1).cv()},2,1705)) goto _0;
_0:
_1:
;
	}

}
