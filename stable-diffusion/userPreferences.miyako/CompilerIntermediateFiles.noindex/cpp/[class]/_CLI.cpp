extern Txt Kchmod_20_2Bx_20;
extern Txt KexecutableName;
extern Txt KplatformPath;
extern Txt Ktrue;
extern Txt k2y$RrLLxafc;
extern Txt k6Nsk9JOUrts;
extern Txt kNXRBf7MoS1g;
extern unsigned char D_proc___CLI_2E__chmod[];
void proc___CLI_2E__chmod( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI_2E__chmod);
	if (!ctx->doingAbort && c.f.fLine==0) {
		{
			Bool t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1572)) goto _0;
			if (!(t0.get())) goto _2;
		}
		{
			Obj t1;
			c.f.fLine=4;
			if (g->Call(ctx,(PCV[]){t1.cv()},0,1470)) goto _0;
			Variant t2;
			if (g->Call(ctx,(PCV[]){t2.cv(),t1.cv(),k2y$RrLLxafc.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t3;
			if (g->Call(ctx,(PCV[]){t3.cv(),t2.cv(),KplatformPath.cv(),Long(11).cv()},3,1496)) goto _0;
			Txt t4;
			if (!g->GetValue(ctx,(PCV[]){t4.cv(),t3.cv(),nullptr})) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,kNXRBf7MoS1g.cv(),t4.cv()},2,812)) goto _0;
		}
		c.f.fLine=5;
		if (g->Call(ctx,(PCV[]){nullptr,k6Nsk9JOUrts.cv(),Ktrue.cv()},2,812)) goto _0;
		g->Check(ctx);
		{
			Obj t5;
			c.f.fLine=6;
			if (g->Call(ctx,(PCV[]){t5.cv()},0,1470)) goto _0;
			Variant t6;
			if (g->Call(ctx,(PCV[]){t6.cv(),t5.cv(),KexecutableName.cv(),Long(11).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t7;
			if (g->OperationOnAny(ctx,0,Kchmod_20_2Bx_20.cv(),t6.cv(),t7.cv())) goto _0;
			Txt t8;
			if (!g->GetValue(ctx,(PCV[]){t8.cv(),t7.cv(),nullptr})) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t8.cv()},1,811)) goto _0;
		}
_2:
_0:
_1:
;
	}

}
extern Txt Knew;
extern Txt KplatformPath;
extern unsigned char D_proc___CLI_2Eexpand[];
void proc___CLI_2Eexpand( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI_2Eexpand);
	if (!ctx->doingAbort && c.f.fLine==0) {
		new ( outResult) Obj();
		c.f.fLine=2;
		{
			Obj t0;
			if (g->Call(ctx,(PCV[]){t0.cv(),Parm<Obj>(inParams,1).cv()},1,1730)) goto _0;
			g->Check(ctx);
			Variant t1;
			if (g->GetMember(ctx,Parm<Obj>(inParams,1).cv(),KplatformPath.cv(),t1.cv())) goto _0;
			Variant t2;
			if (g->Call(ctx,(PCV[]){t2.cv(),t0.cv(),Knew.cv(),t1.cv(),Long(1).cv()},4,1498)) goto _0;
			Obj t3;
			if (!g->GetValue(ctx,(PCV[]){t3.cv(),t2.cv(),nullptr})) goto _0;
			Res<Obj>(outResult)=t3.get();
		}
_0:
_1:
;
	}

}
extern Txt K__platform;
extern unsigned char D_proc___CLI_2Eget_20platform[];
void proc___CLI_2Eget_20platform( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI_2Eget_20platform);
	if (!ctx->doingAbort && c.f.fLine==0) {
		new ( outResult) Txt();
		{
			Obj t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			Variant t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv(),K__platform.cv(),Long(11).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Txt t2;
			if (!g->GetValue(ctx,(PCV[]){t2.cv(),t1.cv(),nullptr})) goto _0;
			Res<Txt>(outResult)=t2.get();
		}
_0:
_1:
;
	}

}
extern Txt K_22;
extern Txt K_26_7C_3C_3E_28_29_25_5E_22_20;
extern Txt K_5C;
extern Txt K_5C_22;
extern Txt kLLQF6tmrvJ4;
extern unsigned char D_proc___CLI_2Eescape[];
void proc___CLI_2Eescape( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI_2Eescape);
	if (!ctx->doingAbort && c.f.fLine==0) {
		Long v2;
		Long v3;
		Long v1;
		Long v0;
		Txt lmetacharacter;
		Txt lmetacharacters;
		Bool lshoudQuote;
		Long llen;
		Long li;
		new ( outResult) Txt();
		c.f.fLine=2;
		Res<Txt>(outResult)=Parm<Txt>(inParams,1).get();
		{
			Bool t0;
			c.f.fLine=7;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1573)) goto _0;
			if (!(t0.get())) goto _3;
		}
		lshoudQuote=Bool(0).get();
		lmetacharacters=K_26_7C_3C_3E_28_29_25_5E_22_20.get();
		{
			Long t1;
			t1=lmetacharacters.get().fLength;
			llen=t1.get();
		}
		li=1;
		v0=llen.get();
		asm volatile("");
		goto _4;
_6:
		{
			Txt t2;
			c.f.fLine=20;
			if (g->Call(ctx,(PCV[]){t2.cv(),lmetacharacters.cv(),li.cv(),Long(1).cv()},3,12)) goto _0;
			lmetacharacter=t2.get();
		}
		c.f.fLine=21;
		{
			Long t3;
			if (g->Call(ctx,(PCV[]){t3.cv(),lmetacharacter.cv(),Res<Txt>(outResult).cv(),Ref((d4_enums::optyp)3).cv()},3,15)) goto _0;
			Bool t4;
			t4=0!=t3.get();
			lshoudQuote=lshoudQuote.get()||t4.get();
		}
		if (!(lshoudQuote.get())) goto _8;
		li=llen.get();
_8:
_5:
		li=li.get()+1;
_4:
		if (li.get()<=v0.get()) goto _6;
_7:
		if (!(lshoudQuote.get())) goto _9;
		{
			Long t8;
			c.f.fLine=28;
			t8=Res<Txt>(outResult).get().fLength;
			Txt t9;
			if (g->Call(ctx,(PCV[]){t9.cv(),Res<Txt>(outResult).cv(),t8.cv()},2,12)) goto _0;
			Bool t10;
			t10=g->CompareString(ctx,t9.get(),K_5C.get())==0;
			if (!(t10.get())) goto _10;
		}
		{
			Txt t11;
			g->AddString(K_22.get(),Res<Txt>(outResult).get(),t11.get());
			c.f.fLine=29;
			g->AddString(t11.get(),K_5C_22.get(),Res<Txt>(outResult).get());
		}
		asm volatile("");
		goto _11;
_10:
		{
			Txt t13;
			g->AddString(K_22.get(),Res<Txt>(outResult).get(),t13.get());
			c.f.fLine=31;
			g->AddString(t13.get(),K_22.get(),Res<Txt>(outResult).get());
		}
_11:
_9:
		asm volatile("");
		goto _2;
_3:
		{
			Bool t15;
			c.f.fLine=35;
			if (g->Call(ctx,(PCV[]){t15.cv()},0,1572)) goto _0;
			if (!(t15.get())) goto _12;
		}
		lmetacharacters=kLLQF6tmrvJ4.get();
		li=1;
		{
			Long t16;
			t16=lmetacharacters.get().fLength;
			v2=t16.get();
		}
		asm volatile("");
		goto _13;
_15:
		{
			Txt t17;
			c.f.fLine=44;
			if (g->Call(ctx,(PCV[]){t17.cv(),lmetacharacters.cv(),li.cv(),Long(1).cv()},3,12)) goto _0;
			lmetacharacter=t17.get();
		}
		{
			Txt t18;
			g->AddString(K_5C.get(),lmetacharacter.get(),t18.get());
			c.f.fLine=45;
			Txt t19;
			if (g->Call(ctx,(PCV[]){t19.cv(),Res<Txt>(outResult).cv(),lmetacharacter.cv(),t18.cv(),Ref((d4_enums::optyp)3).cv()},4,233)) goto _0;
			Res<Txt>(outResult)=t19.get();
		}
_14:
		li=li.get()+1;
_13:
		if (li.get()<=v2.get()) goto _15;
_16:
		asm volatile("");
		goto _2;
_12:
_2:
_0:
_1:
;
	}

}
extern Txt K__executablePath;
extern unsigned char D_proc___CLI_2Eget_20executablePath[];
void proc___CLI_2Eget_20executablePath( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI_2Eget_20executablePath);
	if (!ctx->doingAbort && c.f.fLine==0) {
		new ( outResult) Txt();
		{
			Obj t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			Variant t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv(),K__executablePath.cv(),Long(11).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Txt t2;
			if (!g->GetValue(ctx,(PCV[]){t2.cv(),t1.cv(),nullptr})) goto _0;
			Res<Txt>(outResult)=t2.get();
		}
_0:
_1:
;
	}

}
extern Txt K__executableFile;
extern unsigned char D_proc___CLI_2Eget_20executableFile[];
void proc___CLI_2Eget_20executableFile( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI_2Eget_20executableFile);
	if (!ctx->doingAbort && c.f.fLine==0) {
		new ( outResult) Obj();
		{
			Obj t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			Variant t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv(),K__executableFile.cv(),Long(56).cv()},3,1496)) goto _0;
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
extern Txt kZGph2nYVvXQ;
extern unsigned char D_proc___CLI_2Eget_20currentDirectory[];
void proc___CLI_2Eget_20currentDirectory( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI_2Eget_20currentDirectory);
	if (!ctx->doingAbort && c.f.fLine==0) {
		new ( outResult) Obj();
		{
			Obj t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			Variant t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv(),kZGph2nYVvXQ.cv(),Long(56).cv()},3,1496)) goto _0;
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
extern Txt K__executableName;
extern unsigned char D_proc___CLI_2Eget_20executableName[];
void proc___CLI_2Eget_20executableName( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI_2Eget_20executableName);
	if (!ctx->doingAbort && c.f.fLine==0) {
		new ( outResult) Txt();
		{
			Obj t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			Variant t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv(),K__executableName.cv(),Long(11).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Txt t2;
			if (!g->GetValue(ctx,(PCV[]){t2.cv(),t1.cv(),nullptr})) goto _0;
			Res<Txt>(outResult)=t2.get();
		}
_0:
_1:
;
	}

}
extern Txt K__EOL;
extern unsigned char D_proc___CLI_2Eget_20EOL[];
void proc___CLI_2Eget_20EOL( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI_2Eget_20EOL);
	if (!ctx->doingAbort && c.f.fLine==0) {
		new ( outResult) Txt();
		{
			Obj t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			Variant t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv(),K__EOL.cv(),Long(11).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Txt t2;
			if (!g->GetValue(ctx,(PCV[]){t2.cv(),t1.cv(),nullptr})) goto _0;
			Res<Txt>(outResult)=t2.get();
		}
_0:
_1:
;
	}

}
extern Txt K__name;
extern unsigned char D_proc___CLI_2Eget_20name[];
void proc___CLI_2Eget_20name( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI_2Eget_20name);
	if (!ctx->doingAbort && c.f.fLine==0) {
		new ( outResult) Txt();
		{
			Obj t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			Variant t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv(),K__name.cv(),Long(11).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Txt t2;
			if (!g->GetValue(ctx,(PCV[]){t2.cv(),t1.cv(),nullptr})) goto _0;
			Res<Txt>(outResult)=t2.get();
		}
_0:
_1:
;
	}

}
extern Txt K_22;
extern unsigned char D_proc___CLI_2Equote[];
void proc___CLI_2Equote( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI_2Equote);
	if (!ctx->doingAbort && c.f.fLine==0) {
		new ( outResult) Txt();
		{
			Txt t0;
			g->AddString(K_22.get(),Parm<Txt>(inParams,1).get(),t0.get());
			c.f.fLine=2;
			g->AddString(t0.get(),K_22.get(),Res<Txt>(outResult).get());
		}
_0:
_1:
;
	}

}
extern Txt K__controller;
extern unsigned char D_proc___CLI_2Eget_20controller[];
void proc___CLI_2Eget_20controller( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI_2Eget_20controller);
	if (!ctx->doingAbort && c.f.fLine==0) {
		new ( outResult) Obj();
		{
			Obj t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			Variant t1;
			if (g->Call(ctx,(PCV[]){t1.cv(),t0.cv(),K__controller.cv(),Long(56).cv()},3,1496)) goto _0;
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
extern Txt KWindows;
extern Txt K_0A;
extern Txt K_0D_0A;
extern Txt K_2Eexe;
extern Txt K_2FRESOURCES_2Fbin;
extern Txt K__CLI__Controller;
extern Txt K__EOL;
extern Txt K__chmod;
extern Txt K__controller;
extern Txt K__executableFile;
extern Txt K__executableName;
extern Txt K__executablePath;
extern Txt K__name;
extern Txt K__platform;
extern Txt KexecutableName;
extern Txt Kexists;
extern Txt Kexpand;
extern Txt Kfile;
extern Txt Kfolder;
extern Txt KmacOS;
extern Txt Kname;
extern Txt Knew;
extern Txt Kpath;
extern Txt Kplatform;
extern Txt KplatformPath;
extern Txt k2y$RrLLxafc;
extern Txt kZGph2nYVvXQ;
extern unsigned char D_proc___CLI_3Aconstructor[];
void proc___CLI_3Aconstructor( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc___CLI_3Aconstructor);
	if (!ctx->doingAbort && c.f.fLine==0) {
		{
			Obj t0;
			c.f.fLine=2;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1470)) goto _0;
			Obj t1;
			if (g->Call(ctx,(PCV[]){t1.cv()},0,1470)) goto _0;
			Obj t2;
			if (g->Call(ctx,(PCV[]){t2.cv(),t1.cv()},1,1730)) goto _0;
			g->Check(ctx);
			Variant t3;
			if (g->GetMember(ctx,t2.cv(),Kname.cv(),t3.cv())) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t0.cv(),K__name.cv(),t3.cv(),Long(11).cv()},4,1497)) goto _0;
		}
		{
			Bool t4;
			c.f.fLine=5;
			if (g->Call(ctx,(PCV[]){t4.cv()},0,1572)) goto _0;
			if (!(t4.get())) goto _3;
		}
		{
			Obj t5;
			c.f.fLine=6;
			if (g->Call(ctx,(PCV[]){t5.cv()},0,1470)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t5.cv(),K__platform.cv(),KmacOS.cv(),Long(11).cv()},4,1497)) goto _0;
			g->Check(ctx);
		}
		{
			Obj t6;
			c.f.fLine=7;
			if (g->Call(ctx,(PCV[]){t6.cv()},0,1470)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t6.cv(),K__executableName.cv(),Parm<Txt>(inParams,1).cv(),Long(11).cv()},4,1497)) goto _0;
			g->Check(ctx);
		}
		{
			Obj t7;
			c.f.fLine=8;
			if (g->Call(ctx,(PCV[]){t7.cv()},0,1470)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t7.cv(),K__EOL.cv(),K_0A.cv(),Long(11).cv()},4,1497)) goto _0;
			g->Check(ctx);
		}
		asm volatile("");
		goto _2;
_3:
		{
			Bool t8;
			c.f.fLine=9;
			if (g->Call(ctx,(PCV[]){t8.cv()},0,1573)) goto _0;
			if (!(t8.get())) goto _4;
		}
		{
			Obj t9;
			c.f.fLine=10;
			if (g->Call(ctx,(PCV[]){t9.cv()},0,1470)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t9.cv(),K__platform.cv(),KWindows.cv(),Long(11).cv()},4,1497)) goto _0;
			g->Check(ctx);
		}
		{
			Obj t10;
			c.f.fLine=11;
			if (g->Call(ctx,(PCV[]){t10.cv()},0,1470)) goto _0;
			Txt t11;
			g->AddString(Parm<Txt>(inParams,1).get(),K_2Eexe.get(),t11.get());
			if (g->Call(ctx,(PCV[]){nullptr,t10.cv(),K__executableName.cv(),t11.cv(),Long(11).cv()},4,1497)) goto _0;
			g->Check(ctx);
		}
		{
			Obj t12;
			c.f.fLine=12;
			if (g->Call(ctx,(PCV[]){t12.cv()},0,1470)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t12.cv(),K__EOL.cv(),K_0D_0A.cv(),Long(11).cv()},4,1497)) goto _0;
			g->Check(ctx);
		}
		asm volatile("");
		goto _2;
_4:
_2:
		{
			Obj t13;
			c.f.fLine=15;
			if (g->Call(ctx,(PCV[]){t13.cv()},0,1470)) goto _0;
			Obj t14;
			if (g->Call(ctx,(PCV[]){t14.cv()},0,1470)) goto _0;
			Obj t15;
			if (g->Call(ctx,(PCV[]){t15.cv(),K_2FRESOURCES_2Fbin.cv()},1,1567)) goto _0;
			g->Check(ctx);
			Obj t16;
			if (g->Call(ctx,(PCV[]){t16.cv()},0,1470)) goto _0;
			Variant t17;
			if (g->Call(ctx,(PCV[]){t17.cv(),t16.cv(),Kplatform.cv(),Long(11).cv()},3,1496)) goto _0;
			Variant t18;
			if (g->Call(ctx,(PCV[]){t18.cv(),t15.cv(),Kfolder.cv(),t17.cv()},3,1498)) goto _0;
			Variant t19;
			if (g->Call(ctx,(PCV[]){t19.cv(),t14.cv(),Kexpand.cv(),t18.cv()},3,1498)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t13.cv(),kZGph2nYVvXQ.cv(),t19.cv(),Long(56).cv()},4,1497)) goto _0;
		}
		{
			Obj t20;
			c.f.fLine=17;
			if (g->Call(ctx,(PCV[]){t20.cv()},0,1470)) goto _0;
			Obj t21;
			if (g->Call(ctx,(PCV[]){t21.cv()},0,1470)) goto _0;
			Variant t22;
			if (g->Call(ctx,(PCV[]){t22.cv(),t21.cv(),k2y$RrLLxafc.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Obj t23;
			if (g->Call(ctx,(PCV[]){t23.cv()},0,1470)) goto _0;
			Variant t24;
			if (g->Call(ctx,(PCV[]){t24.cv(),t23.cv(),KexecutableName.cv(),Long(11).cv()},3,1496)) goto _0;
			Variant t25;
			if (g->Call(ctx,(PCV[]){t25.cv(),t22.cv(),Kfile.cv(),t24.cv()},3,1498)) goto _0;
			Variant t26;
			if (g->Call(ctx,(PCV[]){t26.cv(),t25.cv(),Kpath.cv(),Long(11).cv()},3,1496)) goto _0;
			Obj t27;
			if (g->Call(ctx,(PCV[]){t27.cv(),t26.cv()},1,1566)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t20.cv(),K__executableFile.cv(),t27.cv(),Long(56).cv()},4,1497)) goto _0;
		}
		{
			Obj t28;
			c.f.fLine=19;
			if (g->Call(ctx,(PCV[]){t28.cv()},0,1470)) goto _0;
			Variant t29;
			if (g->Call(ctx,(PCV[]){t29.cv(),t28.cv(),K__executableFile.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Variant t30;
			if (g->Call(ctx,(PCV[]){t30.cv(),t29.cv(),Kexists.cv(),Long(10).cv()},3,1496)) goto _0;
			Bool t31;
			if (!g->GetValue(ctx,(PCV[]){t31.cv(),t30.cv(),nullptr})) goto _0;
			if (!(t31.get())) goto _5;
		}
		{
			Bool t32;
			c.f.fLine=24;
			if (g->Call(ctx,(PCV[]){t32.cv()},0,1572)) goto _0;
			if (!(t32.get())) goto _7;
		}
		{
			Obj t33;
			c.f.fLine=25;
			if (g->Call(ctx,(PCV[]){t33.cv()},0,1470)) goto _0;
			Obj t34;
			if (g->Call(ctx,(PCV[]){t34.cv()},0,1470)) goto _0;
			Variant t35;
			if (g->Call(ctx,(PCV[]){t35.cv(),t34.cv(),k2y$RrLLxafc.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Obj t36;
			if (g->Call(ctx,(PCV[]){t36.cv()},0,1470)) goto _0;
			Variant t37;
			if (g->Call(ctx,(PCV[]){t37.cv(),t36.cv(),KexecutableName.cv(),Long(11).cv()},3,1496)) goto _0;
			Variant t38;
			if (g->Call(ctx,(PCV[]){t38.cv(),t35.cv(),Kfile.cv(),t37.cv()},3,1498)) goto _0;
			Variant t39;
			if (g->Call(ctx,(PCV[]){t39.cv(),t38.cv(),Kpath.cv(),Long(11).cv()},3,1496)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t33.cv(),K__executablePath.cv(),t39.cv(),Long(11).cv()},4,1497)) goto _0;
		}
		asm volatile("");
		goto _6;
_7:
		{
			Bool t40;
			c.f.fLine=26;
			if (g->Call(ctx,(PCV[]){t40.cv()},0,1573)) goto _0;
			if (!(t40.get())) goto _8;
		}
		{
			Obj t41;
			c.f.fLine=27;
			if (g->Call(ctx,(PCV[]){t41.cv()},0,1470)) goto _0;
			Obj t42;
			if (g->Call(ctx,(PCV[]){t42.cv()},0,1470)) goto _0;
			Variant t43;
			if (g->Call(ctx,(PCV[]){t43.cv(),t42.cv(),k2y$RrLLxafc.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Obj t44;
			if (g->Call(ctx,(PCV[]){t44.cv()},0,1470)) goto _0;
			Variant t45;
			if (g->Call(ctx,(PCV[]){t45.cv(),t44.cv(),KexecutableName.cv(),Long(11).cv()},3,1496)) goto _0;
			Variant t46;
			if (g->Call(ctx,(PCV[]){t46.cv(),t43.cv(),Kfile.cv(),t45.cv()},3,1498)) goto _0;
			Variant t47;
			if (g->Call(ctx,(PCV[]){t47.cv(),t46.cv(),KplatformPath.cv(),Long(11).cv()},3,1496)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t41.cv(),K__executablePath.cv(),t47.cv(),Long(11).cv()},4,1497)) goto _0;
		}
		asm volatile("");
		goto _6;
_8:
_6:
		{
			Obj t48;
			c.f.fLine=30;
			if (g->Call(ctx,(PCV[]){t48.cv()},0,1470)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t48.cv(),K__chmod.cv()},2,1500)) goto _0;
			g->Check(ctx);
		}
		asm volatile("");
		goto _9;
_5:
		{
			Obj t49;
			c.f.fLine=36;
			if (g->Call(ctx,(PCV[]){t49.cv()},0,1470)) goto _0;
			Obj t50;
			if (g->Call(ctx,(PCV[]){t50.cv()},0,1470)) goto _0;
			Variant t51;
			if (g->Call(ctx,(PCV[]){t51.cv(),t50.cv(),KexecutableName.cv(),Long(11).cv()},3,1496)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,t49.cv(),K__executablePath.cv(),t51.cv(),Long(11).cv()},4,1497)) goto _0;
		}
_9:
		{
			Bool t52;
			t52=Parm<Obj>(inParams,2).isNull();
			if (!(t52.get())) goto _10;
		}
		{
			Obj t53;
			c.f.fLine=40;
			if (g->Call(ctx,(PCV[]){t53.cv()},0,1470)) goto _0;
			Obj t54;
			if (g->Call(ctx,(PCV[]){t54.cv()},0,1710)) goto _0;
			Variant t55;
			if (g->Call(ctx,(PCV[]){t55.cv(),t54.cv(),K__CLI__Controller.cv(),Long(56).cv()},3,1496)) goto _0;
			g->Check(ctx);
			Obj t56;
			if (g->Call(ctx,(PCV[]){t56.cv()},0,1470)) goto _0;
			Variant t57;
			if (g->Call(ctx,(PCV[]){t57.cv(),t55.cv(),Knew.cv(),t56.cv()},3,1498)) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t53.cv(),K__controller.cv(),t57.cv(),Long(56).cv()},4,1497)) goto _0;
		}
		asm volatile("");
		goto _11;
_10:
		{
			Obj t58;
			c.f.fLine=42;
			if (g->Call(ctx,(PCV[]){t58.cv()},0,1470)) goto _0;
			Obj t59;
			if (g->Call(ctx,(PCV[]){t59.cv()},0,1470)) goto _0;
			Variant t60;
			if (g->Call(ctx,(PCV[]){t60.cv(),Parm<Obj>(inParams,2).cv(),Knew.cv(),t59.cv()},3,1498)) goto _0;
			g->Check(ctx);
			if (g->Call(ctx,(PCV[]){nullptr,t58.cv(),K__controller.cv(),t60.cv(),Long(56).cv()},4,1497)) goto _0;
		}
_11:
_0:
_1:
;
	}

}
