extern unsigned char D_proc_ONRESPONSE[];
void proc_ONRESPONSE( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc_ONRESPONSE);
	if (!ctx->doingAbort && c.f.fLine==0) {
_0:
_1:
;
	}

}
