/**
 * Copyright (c) 2022 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#include "Heavy_wstd_eq.hpp"

#include <new>

#define Context(_c) static_cast<Heavy_wstd_eq *>(_c)


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_wstd_eq_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_wstd_eq));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_wstd_eq(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_wstd_eq_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_wstd_eq));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_wstd_eq(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_wstd_eq_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_wstd_eq();
    // free memory
    hv_free(instance);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_wstd_eq::Heavy_wstd_eq(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sLine_init(&sLine_JIZCItgG);
  numBytes += sLine_init(&sLine_QErnWAu2);
  numBytes += sLine_init(&sLine_mouepVdo);
  numBytes += sLine_init(&sLine_1OOQyxGa);
  numBytes += sLine_init(&sLine_0P2v0WAj);
  numBytes += sBiquad_init(&sBiquad_s_HJdbwGLr);
  numBytes += sLine_init(&sLine_dIuHBYC7);
  numBytes += sLine_init(&sLine_2fjRtvkO);
  numBytes += sLine_init(&sLine_kJMyAj6v);
  numBytes += sLine_init(&sLine_uR2KHnk8);
  numBytes += sLine_init(&sLine_dEzpSIr6);
  numBytes += sBiquad_init(&sBiquad_s_P4VzCk6R);
  numBytes += sLine_init(&sLine_TJ7GUUQc);
  numBytes += sLine_init(&sLine_p0AND5Yy);
  numBytes += sLine_init(&sLine_snMtXBTZ);
  numBytes += sLine_init(&sLine_9OMPI0DS);
  numBytes += sLine_init(&sLine_ehkIgxvU);
  numBytes += sBiquad_init(&sBiquad_s_lZy7VKa9);
  numBytes += sLine_init(&sLine_CxcHIV8W);
  numBytes += sLine_init(&sLine_wcAHchiR);
  numBytes += sLine_init(&sLine_AaO6zPYS);
  numBytes += sLine_init(&sLine_PLF4KN1h);
  numBytes += sLine_init(&sLine_8WloziL8);
  numBytes += sBiquad_init(&sBiquad_s_FVCwx8nw);
  numBytes += sLine_init(&sLine_ZBSdFStx);
  numBytes += sLine_init(&sLine_DhBlLOfS);
  numBytes += sLine_init(&sLine_t0cetnap);
  numBytes += sLine_init(&sLine_1jKM1RTJ);
  numBytes += sLine_init(&sLine_2r6UQ34S);
  numBytes += sBiquad_init(&sBiquad_s_VBMpXW4l);
  numBytes += sLine_init(&sLine_6GMOfG4G);
  numBytes += sLine_init(&sLine_mZQBFoqC);
  numBytes += sLine_init(&sLine_hYO8Bq9A);
  numBytes += sLine_init(&sLine_EoITFEqD);
  numBytes += sBiquad_init(&sBiquad_s_9SKvwAbC);
  numBytes += sLine_init(&sLine_sH8Jxj6n);
  numBytes += sLine_init(&sLine_ovVX7LkW);
  numBytes += sLine_init(&sLine_NODZkFYZ);
  numBytes += sLine_init(&sLine_dFLvO4VQ);
  numBytes += sLine_init(&sLine_ZqQJqLSi);
  numBytes += sBiquad_init(&sBiquad_s_3XSDtuwk);
  numBytes += sLine_init(&sLine_8JIfwbyB);
  numBytes += sLine_init(&sLine_8ww4EGGu);
  numBytes += sLine_init(&sLine_4d0LKZ3d);
  numBytes += sLine_init(&sLine_R2CAJFYM);
  numBytes += sLine_init(&sLine_tzGiGQWr);
  numBytes += sBiquad_init(&sBiquad_s_Xmh66GYa);
  numBytes += sLine_init(&sLine_lv85JNTU);
  numBytes += sLine_init(&sLine_ugXoyMlg);
  numBytes += sLine_init(&sLine_C39A06R9);
  numBytes += sLine_init(&sLine_JyEr8Y3C);
  numBytes += sLine_init(&sLine_ja0JIiAC);
  numBytes += sBiquad_init(&sBiquad_s_edcgEzxw);
  numBytes += sLine_init(&sLine_kc5oHDBt);
  numBytes += sLine_init(&sLine_UUKTXyyf);
  numBytes += sLine_init(&sLine_MV2J712n);
  numBytes += sLine_init(&sLine_HJ9AyKrd);
  numBytes += sLine_init(&sLine_Y1P2AAAW);
  numBytes += sBiquad_init(&sBiquad_s_J8ndMwwZ);
  numBytes += sLine_init(&sLine_PjyqLr0E);
  numBytes += sLine_init(&sLine_WhPyEO3R);
  numBytes += sLine_init(&sLine_5RG3o5Lh);
  numBytes += sLine_init(&sLine_G1ysAmHZ);
  numBytes += sLine_init(&sLine_OzTercbZ);
  numBytes += sBiquad_init(&sBiquad_s_aWsuVZI8);
  numBytes += sLine_init(&sLine_Lkkymjs2);
  numBytes += sLine_init(&sLine_bwBUaRYx);
  numBytes += sLine_init(&sLine_r61uHlAq);
  numBytes += sLine_init(&sLine_ezlLygMw);
  numBytes += sLine_init(&sLine_cDIjLYjB);
  numBytes += sBiquad_init(&sBiquad_s_H7k0tUos);
  numBytes += sLine_init(&sLine_EHa9ktCW);
  numBytes += sLine_init(&sLine_U9fDmIJ3);
  numBytes += sLine_init(&sLine_Ue3T7NXd);
  numBytes += sLine_init(&sLine_ruVvxswo);
  numBytes += sLine_init(&sLine_l3fYti6K);
  numBytes += sBiquad_init(&sBiquad_s_US40KNpM);
  numBytes += sLine_init(&sLine_8tMwStS8);
  numBytes += sLine_init(&sLine_8yBMw5rJ);
  numBytes += sLine_init(&sLine_RIWIBagb);
  numBytes += sLine_init(&sLine_w7wZGwm5);
  numBytes += sLine_init(&sLine_uCx77GAz);
  numBytes += sBiquad_init(&sBiquad_s_5THKSpKG);
  numBytes += sLine_init(&sLine_Rd1TVp0A);
  numBytes += sLine_init(&sLine_xAvDQ3Nm);
  numBytes += sLine_init(&sLine_FKdpxfW2);
  numBytes += sLine_init(&sLine_d0DZG5N3);
  numBytes += sLine_init(&sLine_TsOGu6EH);
  numBytes += sBiquad_init(&sBiquad_s_VVDknN9F);
  numBytes += sLine_init(&sLine_vq700BJN);
  numBytes += sLine_init(&sLine_i9GvfDsr);
  numBytes += sLine_init(&sLine_I1vncudL);
  numBytes += sLine_init(&sLine_rno2IaiJ);
  numBytes += sLine_init(&sLine_HgwSifwP);
  numBytes += sBiquad_init(&sBiquad_s_64S6uzOR);
  numBytes += sLine_init(&sLine_RYOuD3Q5);
  numBytes += sLine_init(&sLine_PdYbzBRQ);
  numBytes += sLine_init(&sLine_7pUpOcxF);
  numBytes += sLine_init(&sLine_DlsYGLDY);
  numBytes += sBiquad_init(&sBiquad_s_5ZEDhamU);
  numBytes += sLine_init(&sLine_1RKzYP4D);
  numBytes += sLine_init(&sLine_2jjh3cna);
  numBytes += sLine_init(&sLine_H5JewrOc);
  numBytes += sLine_init(&sLine_NbX7M5TN);
  numBytes += sLine_init(&sLine_q34UGJYK);
  numBytes += sBiquad_init(&sBiquad_s_1QZZZnf3);
  numBytes += sLine_init(&sLine_nLfKhxvm);
  numBytes += sLine_init(&sLine_zzqm33Vi);
  numBytes += sLine_init(&sLine_jeFy1iqT);
  numBytes += sLine_init(&sLine_IIerTTpM);
  numBytes += sLine_init(&sLine_e1eH3MOt);
  numBytes += sBiquad_init(&sBiquad_s_aeT5TR0x);
  numBytes += sLine_init(&sLine_VPXdhIMd);
  numBytes += sLine_init(&sLine_mNjNpQGS);
  numBytes += sLine_init(&sLine_WcJcmCe9);
  numBytes += sLine_init(&sLine_spjpFrne);
  numBytes += sLine_init(&sLine_ObqsHhQG);
  numBytes += sBiquad_init(&sBiquad_s_WHveOMFt);
  numBytes += sLine_init(&sLine_jh2eZltk);
  numBytes += sLine_init(&sLine_tgXLWONs);
  numBytes += sLine_init(&sLine_iuhLneex);
  numBytes += sLine_init(&sLine_wCklLQHT);
  numBytes += sLine_init(&sLine_fsdQXEjZ);
  numBytes += sBiquad_init(&sBiquad_s_zlmdiRBF);
  numBytes += sLine_init(&sLine_3AuKKgR1);
  numBytes += sLine_init(&sLine_bcwFn5rP);
  numBytes += sLine_init(&sLine_f32Mh9jI);
  numBytes += sLine_init(&sLine_bG3mC0oE);
  numBytes += sLine_init(&sLine_VaVXtgnd);
  numBytes += sBiquad_init(&sBiquad_s_ipbCpSF5);
  numBytes += cVar_init_f(&cVar_X1yEL0wN, 0.0f);
  numBytes += cVar_init_f(&cVar_tMcdAmM7, 0.0f);
  numBytes += cVar_init_f(&cVar_aka7krRZ, 0.0f);
  numBytes += cVar_init_f(&cVar_7Og75zwE, 0.0f);
  numBytes += cVar_init_f(&cVar_4PjmBRqr, 0.0f);
  numBytes += cBinop_init(&cBinop_guGkRcDt, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_hp9zLRKF, 0.0f);
  numBytes += cVar_init_f(&cVar_1FESJwHE, 0.0f);
  numBytes += cBinop_init(&cBinop_PH8HT6A5, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_Qt3lJd5O, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_CNkaWZwQ, 0.0f);
  numBytes += cVar_init_f(&cVar_J73macBU, 1337.0f);
  numBytes += cVar_init_f(&cVar_8hwdlAOa, 0.4f);
  numBytes += cBinop_init(&cBinop_s49BBdiQ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_416xYu1c, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_VLQHc6TL, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_4JadYsPi, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_J8MePQgs, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_mQublDOp, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_dFkeJa1J, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_dyBHdxk8, 0.0f);
  numBytes += cVar_init_f(&cVar_D5AWwWQi, 20000.0f);
  numBytes += cVar_init_f(&cVar_mCyeIJzh, 0.12f);
  numBytes += cBinop_init(&cBinop_fvLEZsSM, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Q1ekC9wc, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Z44r7hb9, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_WPn1xru3, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_FkCYeJhC, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_LVcvW7B0, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_xf9FZk2I, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_oGflUDMX, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_8SII2Htb, 0.0f);
  numBytes += cVar_init_f(&cVar_WKSRWc4E, 20.0f);
  numBytes += cVar_init_f(&cVar_8U4BaIZ8, 0.2f);
  numBytes += cBinop_init(&cBinop_fQt5Xi1d, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_yIgOOwU5, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_RV57YB9n, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_vi38S3Zr, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_llMKbw8R, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_xpXWmwKP, 0.0f); // __mul
  numBytes += cIf_init(&cIf_UvPtWeZ8, false);
  numBytes += cIf_init(&cIf_cNfAki9G, false);
  numBytes += cIf_init(&cIf_BA2AjRIa, false);
  numBytes += cIf_init(&cIf_jnbuBru8, false);
  numBytes += cIf_init(&cIf_7iQRlqg3, false);
  numBytes += cIf_init(&cIf_FflkraMh, false);
  numBytes += cBinop_init(&cBinop_QwhDWker, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_eyKZK1Op, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_9ZHkLloh, 0.0f);
  numBytes += cVar_init_f(&cVar_OM7PmNz7, 20.0f);
  numBytes += cVar_init_f(&cVar_pwYjxXwR, 0.2f);
  numBytes += cBinop_init(&cBinop_DrIJ0Q96, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_0rTOOH05, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_yTamDcbZ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_x4Skjfc6, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_7CwVeQ1x, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_OBrMV5QR, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_kb82QTZv, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_U1TcPBAg, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_WhUnj7K8, 0.0f);
  numBytes += cVar_init_f(&cVar_0vgO6XPO, 20.0f);
  numBytes += cVar_init_f(&cVar_7bAXRiB6, 0.2f);
  numBytes += cBinop_init(&cBinop_JTfULxjQ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ddrfe7cX, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_FZYOc0xm, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_vYj6X7M1, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_huknT3y8, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_30cfP7c7, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_agmm1xSO, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_Es18HmMB, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_08T3t8O2, 0.0f);
  numBytes += cVar_init_f(&cVar_qgVdsg7B, 1337.0f);
  numBytes += cVar_init_f(&cVar_TZN4gtv3, 0.3f);
  numBytes += cBinop_init(&cBinop_88DxliJP, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_XO5etX6B, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_zte07MMj, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_RU16w1bM, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ez5qIJCs, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_tBD1cWyA, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_61mmWTBu, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_vetfW3Lj, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_FRSd138D, 0.0f);
  numBytes += cVar_init_f(&cVar_2ftN6oT1, 1037.0f);
  numBytes += cVar_init_f(&cVar_9gLw6tKp, 0.4f);
  numBytes += cBinop_init(&cBinop_jgSUHfZ7, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_z7y8RPkN, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_X1XyouYg, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_jfSy8QtO, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_b3WPDJNn, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_336fQNp5, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_GseVUSKp, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_6ynvfKp1, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_Bp5tj4ok, 0.0f);
  numBytes += cVar_init_f(&cVar_wtME6Uov, 48000.0f);
  numBytes += cVar_init_f(&cVar_qJx01nPl, 0.55f);
  numBytes += cBinop_init(&cBinop_ZQEsxKv0, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_sRPH2vAJ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_OKBPZVea, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_LWK4Tgnw, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_9gZQVCSS, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_qLJRXd8t, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_lliUJDoF, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_eaRXXP0N, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_FZcH6v8s, 0.0f);
  numBytes += cVar_init_f(&cVar_UHJrWd3R, 20.0f);
  numBytes += cVar_init_f(&cVar_0pVaJXSZ, 0.45f);
  numBytes += cBinop_init(&cBinop_Gi5LFuwg, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_T4MDLMdE, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ZWWJrmok, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Y1XeIA30, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_HoEhsdnl, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_n6tDLTbH, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_20Q776bT, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_hXRt7dRo, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_XXAcbo4Y, 0.0f);
  numBytes += cVar_init_f(&cVar_LrDL1BTD, 48000.0f);
  numBytes += cVar_init_f(&cVar_28ggcQBe, 0.12f);
  numBytes += cBinop_init(&cBinop_SAfHMsrP, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ZqvOwIz3, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Fb7hneay, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Yg6vVsH2, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_lv5SsGBZ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_SHMo3w51, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Sl3MCOPi, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_NFAivrSE, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_RBJJEh3g, 0.0f);
  numBytes += cVar_init_f(&cVar_Y9I5ZBZD, 48000.0f);
  numBytes += cVar_init_f(&cVar_ftcH9VFt, 0.12f);
  numBytes += cBinop_init(&cBinop_nHyDxMcg, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_qBt6Yn70, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_5RraMR12, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_W318RAO4, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_VmGVj2Zk, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_iR8TFkN2, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_AB1spV1s, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_x0Q3MhOs, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_HWmdoWHt, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_fW7ZkYKw, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_11CKdUhM, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_cmgx9NBb, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_331DZIFI, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_k6PyfFD5, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Gbdsmap3, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_XVzAST01, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_r4Uk3q7Y, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_2Pcwgy44, 0.0f);
  numBytes += cVar_init_f(&cVar_kOHE8oTl, 1337.0f);
  numBytes += cVar_init_f(&cVar_0iINIqik, 0.4f);
  numBytes += cBinop_init(&cBinop_FIw8K2uG, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_qsU3nQFg, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_mQfZcSZ8, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_B4N8ZFqA, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_y8HtCPeZ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_UvJw8thr, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_VwSTipcM, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_HJN5zvKl, 0.0f);
  numBytes += cVar_init_f(&cVar_6cafKgtk, 20000.0f);
  numBytes += cVar_init_f(&cVar_BoQ186Ki, 0.12f);
  numBytes += cBinop_init(&cBinop_GL1LG7TI, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_J06v5yYD, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_rewiAiEL, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_GSacWdsX, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ja4AnvAn, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_NPPJsUWL, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_gBKLUD3o, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_vxhcQGiU, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_nizlHlKk, 0.0f);
  numBytes += cVar_init_f(&cVar_AKSUevQt, 20.0f);
  numBytes += cVar_init_f(&cVar_imyXB36a, 0.2f);
  numBytes += cBinop_init(&cBinop_tkFA5dwr, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_GcZxm1Cb, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_0eShUvDe, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_UNZmVdTO, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_UO6brczF, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_IiaksrBh, 0.0f); // __mul
  numBytes += cIf_init(&cIf_DlScNNaG, false);
  numBytes += cIf_init(&cIf_LiRg470r, false);
  numBytes += cIf_init(&cIf_C0SX6XPG, false);
  numBytes += cIf_init(&cIf_d6TBOl54, false);
  numBytes += cIf_init(&cIf_TMFdKxlq, false);
  numBytes += cIf_init(&cIf_azvUkfT1, false);
  numBytes += cBinop_init(&cBinop_ewq79oGj, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_2nuDAqzZ, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_EHUsOm4q, 0.0f);
  numBytes += cVar_init_f(&cVar_FvYqaoDT, 20.0f);
  numBytes += cVar_init_f(&cVar_YuKdDjg8, 0.2f);
  numBytes += cBinop_init(&cBinop_OfJnEpyj, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_qPud3rYV, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_zcFL05fS, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ghcUsuuj, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_QglZuqQf, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_wWrn26Os, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_4xDH3BEa, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_Ts7vVgIs, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_FrWyiep6, 0.0f);
  numBytes += cVar_init_f(&cVar_fgj51JW5, 20.0f);
  numBytes += cVar_init_f(&cVar_OwncpxSE, 0.2f);
  numBytes += cBinop_init(&cBinop_CuDWHqcF, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Z0kWJY3U, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_riiRQed9, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_068CmPwx, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_khFdmSnD, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_QbMX68LS, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_tfo72dou, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_Ro1EeLsJ, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_3bOxKv4u, 0.0f);
  numBytes += cVar_init_f(&cVar_vXGUJsA2, 1337.0f);
  numBytes += cVar_init_f(&cVar_GiCEwxVr, 0.3f);
  numBytes += cBinop_init(&cBinop_8eaZgnn4, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_hYZ0yeBx, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_zqnKiLkx, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_57zeqwDX, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ouGkGY8o, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_BrZmkZWd, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_sWsdXZkt, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_HCfgy3hm, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_JnHNR5An, 0.0f);
  numBytes += cVar_init_f(&cVar_Od4mGS29, 1037.0f);
  numBytes += cVar_init_f(&cVar_ScleBLJ8, 0.4f);
  numBytes += cBinop_init(&cBinop_SY7kozBK, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_vkJrAjv7, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_NTVGldgC, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_9ICPEsDb, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_bFITaL6g, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_clRIYe7R, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_YiDmkWhh, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_WYGuv6iW, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_oXBuPGm4, 0.0f);
  numBytes += cVar_init_f(&cVar_YKmnTCqa, 48000.0f);
  numBytes += cVar_init_f(&cVar_0z1LE9Yi, 0.55f);
  numBytes += cBinop_init(&cBinop_laXBezeo, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_q8L8vFfR, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_CBTZgbrJ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_eZwyFlxb, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_HF5Xz6be, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ibSDkDog, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_mtOZtVkP, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_8cW4DKPu, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_U9EIL4Z3, 0.0f);
  numBytes += cVar_init_f(&cVar_WWNkb1Bs, 20.0f);
  numBytes += cVar_init_f(&cVar_1a05rG01, 0.45f);
  numBytes += cBinop_init(&cBinop_t8cEVHZl, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Bt33evw5, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_XITMzzAs, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_N6Bl3bI1, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_pIb1LSGO, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_0scmuTe2, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_zrDPvaCA, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_IhSRWCIP, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_7R07iGd8, 0.0f);
  numBytes += cVar_init_f(&cVar_j8b2cAPv, 48000.0f);
  numBytes += cVar_init_f(&cVar_HzIMX3C0, 0.12f);
  numBytes += cBinop_init(&cBinop_tbQkGSMg, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_SDNy4he7, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_kkT0goip, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_QcOVaU1R, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_xynTDDcs, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_pGMEQP2I, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_vBhrNH3l, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_1Lr8mYWh, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_AG09tufW, 0.0f);
  numBytes += cVar_init_f(&cVar_HFyiPOeC, 48000.0f);
  numBytes += cVar_init_f(&cVar_atEo3NBi, 0.12f);
  numBytes += cBinop_init(&cBinop_lSRDYTY1, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_lFWAKVMf, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_5RXg9iwP, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_80DMty1O, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Sawl3pG5, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_WIN8T0IF, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ZJTklZXC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_JtAjI1rH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_i1dw7hND, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_2fLB5Mbi, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_KZOhDse2, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_dBQfmjlY, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Y3Q4QJER, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_d0UQMJbW, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_siORK6KE, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_wstd_eq::~Heavy_wstd_eq() {
  // nothing to free
}

HvTable *Heavy_wstd_eq::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_wstd_eq::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xEC52D849: { // 1048-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_j7jPq2xF_sendMessage);
      break;
    }
    case 0xC4DFA43E: { // 1048-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Hpe5OlMC_sendMessage);
      break;
    }
    case 0x12BEEF18: { // 1048-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rBH1SXV5_sendMessage);
      break;
    }
    case 0x94F93E04: { // 1089-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jGcJLSq3_sendMessage);
      break;
    }
    case 0xEEADE586: { // 1089-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QthhlhBD_sendMessage);
      break;
    }
    case 0xBCA0CAFA: { // 1089-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dIt4a5NB_sendMessage);
      break;
    }
    case 0x21277B02: { // 1130-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ddaO1aeU_sendMessage);
      break;
    }
    case 0xF05031A8: { // 1130-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jPxWsPaX_sendMessage);
      break;
    }
    case 0x1F801CFE: { // 1130-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zI1jPosc_sendMessage);
      break;
    }
    case 0xFC1F7447: { // 1181-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ZyGIg4II_sendMessage);
      break;
    }
    case 0x5888415E: { // 1181-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WgeSZZCR_sendMessage);
      break;
    }
    case 0x21687619: { // 1181-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Z6Ndq3Jq_sendMessage);
      break;
    }
    case 0x1A14721E: { // 1222-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YduBgfRN_sendMessage);
      break;
    }
    case 0x446DC164: { // 1222-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7QVuGES2_sendMessage);
      break;
    }
    case 0x32F45A8B: { // 1222-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bgT2vYno_sendMessage);
      break;
    }
    case 0x1286072C: { // 1263-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rthEiND4_sendMessage);
      break;
    }
    case 0x7902A17C: { // 1263-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_iNu0k2ff_sendMessage);
      break;
    }
    case 0x7A57C19C: { // 1263-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_33E0d4rY_sendMessage);
      break;
    }
    case 0x170C9887: { // 1304-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_73juy3Xb_sendMessage);
      break;
    }
    case 0xED0CBA1C: { // 1304-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6vAmuSge_sendMessage);
      break;
    }
    case 0xDA3A818C: { // 1304-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_KYDt84Ro_sendMessage);
      break;
    }
    case 0x8D0ABB99: { // 1345-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bTtX2kwY_sendMessage);
      break;
    }
    case 0x7D9AE52B: { // 1345-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4cFShlWc_sendMessage);
      break;
    }
    case 0xD6D23887: { // 1345-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_nNBLp2Nq_sendMessage);
      break;
    }
    case 0x9B0684BF: { // 1386-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Mq44tTwd_sendMessage);
      break;
    }
    case 0x9B78B182: { // 1386-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_nm3v15OR_sendMessage);
      break;
    }
    case 0x9D11E421: { // 1386-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zHCsvsj9_sendMessage);
      break;
    }
    case 0x91B51451: { // 1427-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_SfXKgWyS_sendMessage);
      break;
    }
    case 0xBAB14460: { // 1427-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2xlVqp3A_sendMessage);
      break;
    }
    case 0x739602BC: { // 1427-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_n2oVsFbE_sendMessage);
      break;
    }
    case 0xF3F36D3C: { // 1468-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WNsvIoQ6_sendMessage);
      break;
    }
    case 0x3FEAE68C: { // 1468-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Ut0X5B68_sendMessage);
      break;
    }
    case 0xE7A69021: { // 1468-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_nlps4aOb_sendMessage);
      break;
    }
    case 0x44F059E4: { // 1510-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4VhP27dD_sendMessage);
      break;
    }
    case 0xF9035A75: { // 1510-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_e4xZa6W7_sendMessage);
      break;
    }
    case 0xC547E608: { // 1510-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_N6KwVPR4_sendMessage);
      break;
    }
    case 0x60928200: { // 1551-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8WiVvIXd_sendMessage);
      break;
    }
    case 0x30730673: { // 1551-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_hYrx8yU2_sendMessage);
      break;
    }
    case 0x3D69E4B0: { // 1551-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_v0Lmm0An_sendMessage);
      break;
    }
    case 0xCFCFD084: { // 1592-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_95yoQY2G_sendMessage);
      break;
    }
    case 0x79D60C70: { // 1592-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WAD84sPX_sendMessage);
      break;
    }
    case 0x1BB4279E: { // 1592-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ArHUBWem_sendMessage);
      break;
    }
    case 0x8C3E982D: { // 1643-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_16ZPDNVW_sendMessage);
      break;
    }
    case 0xA9C11C62: { // 1643-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Rqlf3Jtm_sendMessage);
      break;
    }
    case 0x6BD790DA: { // 1643-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JRP6DdMm_sendMessage);
      break;
    }
    case 0xB9352237: { // 1684-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JcgcQDY4_sendMessage);
      break;
    }
    case 0x2579F5EA: { // 1684-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JMsEdRae_sendMessage);
      break;
    }
    case 0x231FA378: { // 1684-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Re5Pa0dr_sendMessage);
      break;
    }
    case 0x3614A120: { // 1725-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_OVFX62Nq_sendMessage);
      break;
    }
    case 0x7EC085E0: { // 1725-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_beA3dDhm_sendMessage);
      break;
    }
    case 0xEC9F2C9F: { // 1725-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_IqkvICmX_sendMessage);
      break;
    }
    case 0xED5B2041: { // 1766-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bbigd7Ie_sendMessage);
      break;
    }
    case 0x91CA54ED: { // 1766-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_D1klMwit_sendMessage);
      break;
    }
    case 0x335AB4D8: { // 1766-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Ooo2CFxB_sendMessage);
      break;
    }
    case 0x5B8523C6: { // 1807-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_t9ei2NTX_sendMessage);
      break;
    }
    case 0xEC2DC15D: { // 1807-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_IpydDhpX_sendMessage);
      break;
    }
    case 0x4783B93B: { // 1807-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MuBRdKud_sendMessage);
      break;
    }
    case 0xC07CAC2A: { // 1848-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qf0ceDnp_sendMessage);
      break;
    }
    case 0x83F3FE58: { // 1848-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ahLMPlZV_sendMessage);
      break;
    }
    case 0x8C9FB89B: { // 1848-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_kw7VvPAZ_sendMessage);
      break;
    }
    case 0x79267877: { // 1889-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tU5A1rdx_sendMessage);
      break;
    }
    case 0xE545836: { // 1889-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Jl12oBgM_sendMessage);
      break;
    }
    case 0xB936C12E: { // 1889-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_iWwDDuTr_sendMessage);
      break;
    }
    case 0x8496D368: { // 1930-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Nj4XcvQk_sendMessage);
      break;
    }
    case 0x96E21BCF: { // 1930-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jizggOAv_sendMessage);
      break;
    }
    case 0x6B21B523: { // 1930-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2JTdiF7f_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_n4xZ1g6L_sendMessage);
      break;
    }
    case 0xEFC88786: { // high
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_AkuwnIdf_sendMessage);
      break;
    }
    case 0xF20B1749: { // low
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_R7plTYhA_sendMessage);
      break;
    }
    case 0xD56AFDDF: { // mid
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_a0Pt8Ir0_sendMessage);
      break;
    }
    case 0xA71AF296: { // param1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_lF18vsxE_sendMessage);
      break;
    }
    case 0x7FADC107: { // param2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_CV1Z1794_sendMessage);
      break;
    }
    case 0xBDA09677: { // param3
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_M2TXyEwE_sendMessage);
      break;
    }
    case 0x60F7B64C: { // srate
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DpXKtl7J_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_wstd_eq::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "high";
        info->hash = 0xEFC88786;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = -1.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 1: {
        info->name = "low";
        info->hash = 0xF20B1749;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = -1.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 2: {
        info->name = "mid";
        info->hash = 0xD56AFDDF;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = -1.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.0f;
        break;
      }
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 3;
}



/*
 * Send Function Implementations
 */


void Heavy_wstd_eq::cVar_X1yEL0wN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_YBbGFzgy_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_wvYnVNHU_sendMessage);
}

void Heavy_wstd_eq::cVar_tMcdAmM7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Sh5aINBH_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_imHgPnsf_sendMessage);
}

void Heavy_wstd_eq::cVar_aka7krRZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_tdcYtXhR_sendMessage);
}

void Heavy_wstd_eq::cVar_7Og75zwE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1FESJwHE, 0, m, &cVar_1FESJwHE_sendMessage);
  cPrint_onMessage(_c, m, "q");
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IsZzTSiB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XRXVK9sN_sendMessage);
  cPrint_onMessage(_c, m, "q");
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lKG6QN5x_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EMbENKFE_sendMessage);
}

void Heavy_wstd_eq::cVar_4PjmBRqr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_AGlzsz0n_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_e8qtzdME_sendMessage);
}

void Heavy_wstd_eq::cBinop_p22IY5QW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hp9zLRKF, 0, m, &cVar_hp9zLRKF_sendMessage);
  cPrint_onMessage(_c, m, "freq");
  cVar_onMessage(_c, &Context(_c)->cVar_J73macBU, 0, m, &cVar_J73macBU_sendMessage);
  cPrint_onMessage(_c, m, "freq");
  cVar_onMessage(_c, &Context(_c)->cVar_kOHE8oTl, 0, m, &cVar_kOHE8oTl_sendMessage);
}

void Heavy_wstd_eq::cBinop_tdcYtXhR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_Hp8z7m4P_sendMessage);
}

void Heavy_wstd_eq::cBinop_Hp8z7m4P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_guGkRcDt, HV_BINOP_POW, 1, m, &cBinop_guGkRcDt_sendMessage);
  cMsg_t5gNM1bP_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_guGkRcDt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_p22IY5QW_sendMessage);
}

void Heavy_wstd_eq::cMsg_t5gNM1bP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_guGkRcDt, HV_BINOP_POW, 0, m, &cBinop_guGkRcDt_sendMessage);
}

void Heavy_wstd_eq::cVar_hp9zLRKF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_wstd_eq::cVar_1FESJwHE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_wstd_eq::cMsg_ZVRuR7LH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_6GMOfG4G, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_5DUjq6Dg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_mZQBFoqC, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_c4Ivz8fG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_hYO8Bq9A, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_CavOT1aC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_EoITFEqD, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_VkVRubP2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bbyh51i2_sendMessage);
}

void Heavy_wstd_eq::cSystem_bbyh51i2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PH8HT6A5, HV_BINOP_DIVIDE, 1, m, &cBinop_PH8HT6A5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aLhkeXTt_sendMessage);
}

void Heavy_wstd_eq::cUnop_Px9R17hU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_IX46lCT3_sendMessage);
}

void Heavy_wstd_eq::cMsg_mP8HawRc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_Px9R17hU_sendMessage);
}

void Heavy_wstd_eq::cBinop_IX46lCT3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PH8HT6A5, HV_BINOP_DIVIDE, 0, m, &cBinop_PH8HT6A5_sendMessage);
}

void Heavy_wstd_eq::cCast_aLhkeXTt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mP8HawRc_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_PH8HT6A5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Qt3lJd5O, HV_BINOP_MULTIPLY, 1, m, &cBinop_Qt3lJd5O_sendMessage);
}

void Heavy_wstd_eq::cBinop_Qt3lJd5O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GlS2SWme_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BKwSRQZk_sendMessage);
}

void Heavy_wstd_eq::cUnop_AReZWfrR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_3WiSxXTH_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cUnop_XQCjRTx5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_uGEVRmZO_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_wuiMBcZK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_wJEmeKIP_sendMessage);
}

void Heavy_wstd_eq::cBinop_wJEmeKIP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Qt3lJd5O, HV_BINOP_MULTIPLY, 0, m, &cBinop_Qt3lJd5O_sendMessage);
}

void Heavy_wstd_eq::cBinop_2Lg8X0fC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_9c3TXObQ_sendMessage);
}

void Heavy_wstd_eq::cBinop_9c3TXObQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lCgu3VH4_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_MmQamM5S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VLQHc6TL, HV_BINOP_MULTIPLY, 1, m, &cBinop_VLQHc6TL_sendMessage);
}

void Heavy_wstd_eq::cBinop_y7gNRlD8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CNkaWZwQ, 1, m, &cVar_CNkaWZwQ_sendMessage);
}

void Heavy_wstd_eq::cBinop_gLCbMuBC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4JadYsPi, HV_BINOP_MULTIPLY, 1, m, &cBinop_4JadYsPi_sendMessage);
}

void Heavy_wstd_eq::cMsg_74ePEJJz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_7TquxaIL_sendMessage);
}

void Heavy_wstd_eq::cBinop_7TquxaIL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J8MePQgs, HV_BINOP_MULTIPLY, 1, m, &cBinop_J8MePQgs_sendMessage);
}

void Heavy_wstd_eq::cVar_CNkaWZwQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vmN6FgEE_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cVar_J73macBU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XYWJPWEw_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_wuiMBcZK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_j3pjkV35_sendMessage);
}

void Heavy_wstd_eq::cVar_8hwdlAOa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_2Lg8X0fC_sendMessage);
}

void Heavy_wstd_eq::cCast_GlS2SWme_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_AReZWfrR_sendMessage);
}

void Heavy_wstd_eq::cCast_BKwSRQZk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_XQCjRTx5_sendMessage);
}

void Heavy_wstd_eq::cSend_3WiSxXTH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_rBH1SXV5_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_uGEVRmZO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Hpe5OlMC_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_qehk6ltj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_j7jPq2xF_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_lCgu3VH4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_pM1af5hu_sendMessage);
}

void Heavy_wstd_eq::cBinop_pM1af5hu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_s49BBdiQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_s49BBdiQ_sendMessage);
}

void Heavy_wstd_eq::cBinop_s49BBdiQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_ye6rwTPK_sendMessage);
}

void Heavy_wstd_eq::cBinop_ye6rwTPK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_qehk6ltj_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_vmN6FgEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_IehN2Sd7_sendMessage);
}

void Heavy_wstd_eq::cBinop_IehN2Sd7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Pti7awkD_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_X7Scr86y_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AaBqrc8s_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RJIWIg1X_sendMessage);
}

void Heavy_wstd_eq::cBinop_416xYu1c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZVRuR7LH_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_VLQHc6TL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5DUjq6Dg_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_4JadYsPi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_c4Ivz8fG_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_J8MePQgs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CavOT1aC_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cCast_IsZzTSiB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8hwdlAOa, 1, m, &cVar_8hwdlAOa_sendMessage);
}

void Heavy_wstd_eq::cCast_XRXVK9sN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_J73macBU, 0, m, &cVar_J73macBU_sendMessage);
}

void Heavy_wstd_eq::cCast_XYWJPWEw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8hwdlAOa, 0, m, &cVar_8hwdlAOa_sendMessage);
}

void Heavy_wstd_eq::cCast_j3pjkV35_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CNkaWZwQ, 0, m, &cVar_CNkaWZwQ_sendMessage);
}

void Heavy_wstd_eq::cCast_AaBqrc8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VLQHc6TL, HV_BINOP_MULTIPLY, 0, m, &cBinop_VLQHc6TL_sendMessage);
}

void Heavy_wstd_eq::cCast_Pti7awkD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J8MePQgs, HV_BINOP_MULTIPLY, 0, m, &cBinop_J8MePQgs_sendMessage);
}

void Heavy_wstd_eq::cCast_RJIWIg1X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_416xYu1c, HV_BINOP_MULTIPLY, 0, m, &cBinop_416xYu1c_sendMessage);
}

void Heavy_wstd_eq::cCast_X7Scr86y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4JadYsPi, HV_BINOP_MULTIPLY, 0, m, &cBinop_4JadYsPi_sendMessage);
}

void Heavy_wstd_eq::cMsg_ajiRMnYk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_sH8Jxj6n, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_DPbEBazX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ovVX7LkW, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_YeAxCP0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_NODZkFYZ, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_F2OBc6D6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_dFLvO4VQ, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_qdrtHzzq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ZqQJqLSi, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_Q8vl7Iqm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0HlKkdxS_sendMessage);
}

void Heavy_wstd_eq::cSystem_0HlKkdxS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mQublDOp, HV_BINOP_DIVIDE, 1, m, &cBinop_mQublDOp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OhoIU8X9_sendMessage);
}

void Heavy_wstd_eq::cUnop_5biePoQa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_OJyxVeqX_sendMessage);
}

void Heavy_wstd_eq::cMsg_iEev9dBw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_5biePoQa_sendMessage);
}

void Heavy_wstd_eq::cBinop_OJyxVeqX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mQublDOp, HV_BINOP_DIVIDE, 0, m, &cBinop_mQublDOp_sendMessage);
}

void Heavy_wstd_eq::cCast_OhoIU8X9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iEev9dBw_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_mQublDOp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dFkeJa1J, HV_BINOP_MULTIPLY, 1, m, &cBinop_dFkeJa1J_sendMessage);
}

void Heavy_wstd_eq::cBinop_dFkeJa1J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MHdJJCni_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uw5mIlT0_sendMessage);
}

void Heavy_wstd_eq::cUnop_VZX9ZN8F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_az376NCQ_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cUnop_QbkpSDG2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Dzchx3UX_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_487B5Mty_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_xNCmLD08_sendMessage);
}

void Heavy_wstd_eq::cBinop_xNCmLD08_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dFkeJa1J, HV_BINOP_MULTIPLY, 0, m, &cBinop_dFkeJa1J_sendMessage);
}

void Heavy_wstd_eq::cBinop_jxreAgpt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_s7efwXg1_sendMessage);
}

void Heavy_wstd_eq::cBinop_s7efwXg1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FNfAJ34I_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_oNgn8KtC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q1ekC9wc, HV_BINOP_MULTIPLY, 1, m, &cBinop_Q1ekC9wc_sendMessage);
}

void Heavy_wstd_eq::cMsg_Qc2tsHyA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_F6nJIIoX_sendMessage);
}

void Heavy_wstd_eq::cBinop_F6nJIIoX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_oNgn8KtC_sendMessage);
}

void Heavy_wstd_eq::cMsg_kVO9pKy5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_VUrcTu8A_sendMessage);
}

void Heavy_wstd_eq::cBinop_VUrcTu8A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z44r7hb9, HV_BINOP_MULTIPLY, 1, m, &cBinop_Z44r7hb9_sendMessage);
}

void Heavy_wstd_eq::cBinop_lGmZVkd0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WPn1xru3, HV_BINOP_MULTIPLY, 1, m, &cBinop_WPn1xru3_sendMessage);
}

void Heavy_wstd_eq::cMsg_HARjQxYv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_AEolzJ6Y_sendMessage);
}

void Heavy_wstd_eq::cBinop_AEolzJ6Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_lGmZVkd0_sendMessage);
}

void Heavy_wstd_eq::cBinop_ynlF1kpw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dyBHdxk8, 1, m, &cVar_dyBHdxk8_sendMessage);
}

void Heavy_wstd_eq::cBinop_X92m6OR6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FkCYeJhC, HV_BINOP_MULTIPLY, 1, m, &cBinop_FkCYeJhC_sendMessage);
}

void Heavy_wstd_eq::cMsg_HZPzXTTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_h1alo5qZ_sendMessage);
}

void Heavy_wstd_eq::cBinop_h1alo5qZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LVcvW7B0, HV_BINOP_MULTIPLY, 1, m, &cBinop_LVcvW7B0_sendMessage);
}

void Heavy_wstd_eq::cVar_dyBHdxk8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZKAfjfQ5_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cVar_D5AWwWQi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ay8J8ebc_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_487B5Mty_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W2X0v8iv_sendMessage);
}

void Heavy_wstd_eq::cVar_mCyeIJzh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_jxreAgpt_sendMessage);
}

void Heavy_wstd_eq::cCast_MHdJJCni_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_VZX9ZN8F_sendMessage);
}

void Heavy_wstd_eq::cCast_uw5mIlT0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_QbkpSDG2_sendMessage);
}

void Heavy_wstd_eq::cSend_az376NCQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_dIt4a5NB_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_Dzchx3UX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_QthhlhBD_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_92Ha8XMj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jGcJLSq3_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_FNfAJ34I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_8Ad3lLut_sendMessage);
}

void Heavy_wstd_eq::cBinop_8Ad3lLut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fvLEZsSM, HV_BINOP_MULTIPLY, 1, m, &cBinop_fvLEZsSM_sendMessage);
}

void Heavy_wstd_eq::cBinop_fvLEZsSM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_eq1RADLk_sendMessage);
}

void Heavy_wstd_eq::cBinop_eq1RADLk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_92Ha8XMj_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_ZKAfjfQ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_va2gdchf_sendMessage);
}

void Heavy_wstd_eq::cBinop_va2gdchf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_l6Vs7aLh_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1VaJmjFR_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1gNuItxC_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kYbE2zx9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_w7HMyha5_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Dh7ocuJh_sendMessage);
}

void Heavy_wstd_eq::cBinop_Q1ekC9wc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ajiRMnYk_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_Z44r7hb9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DPbEBazX_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_WPn1xru3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YeAxCP0d_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_FkCYeJhC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_F2OBc6D6_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_LVcvW7B0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qdrtHzzq_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cCast_zYVmPgQV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mCyeIJzh, 1, m, &cVar_mCyeIJzh_sendMessage);
}

void Heavy_wstd_eq::cCast_O8F8fi9q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_D5AWwWQi, 0, m, &cVar_D5AWwWQi_sendMessage);
}

void Heavy_wstd_eq::cCast_w7HMyha5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z44r7hb9, HV_BINOP_MULTIPLY, 0, m, &cBinop_Z44r7hb9_sendMessage);
}

void Heavy_wstd_eq::cCast_1VaJmjFR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LVcvW7B0, HV_BINOP_MULTIPLY, 0, m, &cBinop_LVcvW7B0_sendMessage);
}

void Heavy_wstd_eq::cCast_kYbE2zx9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WPn1xru3, HV_BINOP_MULTIPLY, 0, m, &cBinop_WPn1xru3_sendMessage);
}

void Heavy_wstd_eq::cCast_Dh7ocuJh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q1ekC9wc, HV_BINOP_MULTIPLY, 0, m, &cBinop_Q1ekC9wc_sendMessage);
}

void Heavy_wstd_eq::cCast_1gNuItxC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FkCYeJhC, HV_BINOP_MULTIPLY, 0, m, &cBinop_FkCYeJhC_sendMessage);
}

void Heavy_wstd_eq::cCast_l6Vs7aLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_wstd_eq::cCast_Ay8J8ebc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mCyeIJzh, 0, m, &cVar_mCyeIJzh_sendMessage);
}

void Heavy_wstd_eq::cCast_W2X0v8iv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dyBHdxk8, 0, m, &cVar_dyBHdxk8_sendMessage);
}

void Heavy_wstd_eq::cMsg_BeKTpMd2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_8JIfwbyB, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_956hFODp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_8ww4EGGu, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_jGxCn2O0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_4d0LKZ3d, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_f2P8KFGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_R2CAJFYM, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_WM1X84Ko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_tzGiGQWr, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_KPnWLQOs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hjCiWJW8_sendMessage);
}

void Heavy_wstd_eq::cSystem_hjCiWJW8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xf9FZk2I, HV_BINOP_DIVIDE, 1, m, &cBinop_xf9FZk2I_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HzCcYqAR_sendMessage);
}

void Heavy_wstd_eq::cUnop_dMYIFTBd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_hZon6GWv_sendMessage);
}

void Heavy_wstd_eq::cMsg_vHKVJRwm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_dMYIFTBd_sendMessage);
}

void Heavy_wstd_eq::cBinop_hZon6GWv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xf9FZk2I, HV_BINOP_DIVIDE, 0, m, &cBinop_xf9FZk2I_sendMessage);
}

void Heavy_wstd_eq::cCast_HzCcYqAR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vHKVJRwm_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_xf9FZk2I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oGflUDMX, HV_BINOP_MULTIPLY, 1, m, &cBinop_oGflUDMX_sendMessage);
}

void Heavy_wstd_eq::cBinop_oGflUDMX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ChHNhvwW_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8AVcW940_sendMessage);
}

void Heavy_wstd_eq::cUnop_EdL2ANPA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_O5ILgjPH_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cUnop_FqBpxLpE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_mzga3lcl_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_YBan1uNE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_lIqfnlZk_sendMessage);
}

void Heavy_wstd_eq::cBinop_lIqfnlZk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oGflUDMX, HV_BINOP_MULTIPLY, 0, m, &cBinop_oGflUDMX_sendMessage);
}

void Heavy_wstd_eq::cBinop_rEwVYqNb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_PO6KYjbu_sendMessage);
}

void Heavy_wstd_eq::cBinop_PO6KYjbu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EN8bNJqV_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_uSiBz9gF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8SII2Htb, 1, m, &cVar_8SII2Htb_sendMessage);
}

void Heavy_wstd_eq::cVar_8SII2Htb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mriH37ue_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_Tbg1p0Pl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yIgOOwU5, HV_BINOP_MULTIPLY, 1, m, &cBinop_yIgOOwU5_sendMessage);
}

void Heavy_wstd_eq::cBinop_y3H8bU9k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_Tbg1p0Pl_sendMessage);
}

void Heavy_wstd_eq::cBinop_d7kl0Hrl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_JypVBb5y_sendMessage);
}

void Heavy_wstd_eq::cBinop_JypVBb5y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RV57YB9n, HV_BINOP_MULTIPLY, 1, m, &cBinop_RV57YB9n_sendMessage);
}

void Heavy_wstd_eq::cBinop_mkcLkHfH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vi38S3Zr, HV_BINOP_MULTIPLY, 1, m, &cBinop_vi38S3Zr_sendMessage);
}

void Heavy_wstd_eq::cBinop_6uev5bXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_mkcLkHfH_sendMessage);
}

void Heavy_wstd_eq::cBinop_u0Dglmrc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_llMKbw8R, HV_BINOP_MULTIPLY, 1, m, &cBinop_llMKbw8R_sendMessage);
}

void Heavy_wstd_eq::cMsg_jGSPKbHm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_gGj5GzPJ_sendMessage);
}

void Heavy_wstd_eq::cBinop_gGj5GzPJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xpXWmwKP, HV_BINOP_MULTIPLY, 1, m, &cBinop_xpXWmwKP_sendMessage);
}

void Heavy_wstd_eq::cVar_WKSRWc4E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EeoVScLt_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_YBan1uNE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LYw2cQBt_sendMessage);
}

void Heavy_wstd_eq::cVar_8U4BaIZ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_rEwVYqNb_sendMessage);
}

void Heavy_wstd_eq::cCast_8AVcW940_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_FqBpxLpE_sendMessage);
}

void Heavy_wstd_eq::cCast_ChHNhvwW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_EdL2ANPA_sendMessage);
}

void Heavy_wstd_eq::cSend_O5ILgjPH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_zI1jPosc_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_mzga3lcl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jPxWsPaX_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_uEjwZK4L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ddaO1aeU_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_EN8bNJqV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_BLtPJHFY_sendMessage);
}

void Heavy_wstd_eq::cBinop_BLtPJHFY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fQt5Xi1d, HV_BINOP_MULTIPLY, 1, m, &cBinop_fQt5Xi1d_sendMessage);
}

void Heavy_wstd_eq::cBinop_fQt5Xi1d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_b4ApwMei_sendMessage);
}

void Heavy_wstd_eq::cBinop_b4ApwMei_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_uEjwZK4L_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_mriH37ue_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_TpPcCfTH_sendMessage);
}

void Heavy_wstd_eq::cBinop_TpPcCfTH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1RiRnosy_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NFgBJmds_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mzWvXSVR_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qH1tUdTR_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lAtc6qsr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wfrgetkx_sendMessage);
}

void Heavy_wstd_eq::cBinop_yIgOOwU5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BeKTpMd2_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_RV57YB9n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_956hFODp_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_vi38S3Zr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jGxCn2O0_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_llMKbw8R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_f2P8KFGJ_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_xpXWmwKP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WM1X84Ko_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cCast_oMaRdT3p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8U4BaIZ8, 1, m, &cVar_8U4BaIZ8_sendMessage);
}

void Heavy_wstd_eq::cCast_iW7ws0KC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WKSRWc4E, 0, m, &cVar_WKSRWc4E_sendMessage);
}

void Heavy_wstd_eq::cCast_qH1tUdTR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vi38S3Zr, HV_BINOP_MULTIPLY, 0, m, &cBinop_vi38S3Zr_sendMessage);
}

void Heavy_wstd_eq::cCast_mzWvXSVR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_llMKbw8R, HV_BINOP_MULTIPLY, 0, m, &cBinop_llMKbw8R_sendMessage);
}

void Heavy_wstd_eq::cCast_1RiRnosy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_wstd_eq::cCast_NFgBJmds_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xpXWmwKP, HV_BINOP_MULTIPLY, 0, m, &cBinop_xpXWmwKP_sendMessage);
}

void Heavy_wstd_eq::cCast_wfrgetkx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yIgOOwU5, HV_BINOP_MULTIPLY, 0, m, &cBinop_yIgOOwU5_sendMessage);
}

void Heavy_wstd_eq::cCast_lAtc6qsr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RV57YB9n, HV_BINOP_MULTIPLY, 0, m, &cBinop_RV57YB9n_sendMessage);
}

void Heavy_wstd_eq::cCast_LYw2cQBt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8SII2Htb, 0, m, &cVar_8SII2Htb_sendMessage);
}

void Heavy_wstd_eq::cCast_EeoVScLt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8U4BaIZ8, 0, m, &cVar_8U4BaIZ8_sendMessage);
}

void Heavy_wstd_eq::cIf_UvPtWeZ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_331DZIFI, m);
      break;
    }
    default: return;
  }
}

void Heavy_wstd_eq::cIf_cNfAki9G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_fW7ZkYKw, HV_BINOP_MULTIPLY, 0, m, &cBinop_fW7ZkYKw_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_fW7ZkYKw, HV_BINOP_MULTIPLY, 1, m, &cBinop_fW7ZkYKw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_wstd_eq::cIf_BA2AjRIa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_Gbdsmap3, m);
      break;
    }
    default: return;
  }
}

void Heavy_wstd_eq::cIf_jnbuBru8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_11CKdUhM, HV_BINOP_MULTIPLY, 0, m, &cBinop_11CKdUhM_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_11CKdUhM, HV_BINOP_MULTIPLY, 1, m, &cBinop_11CKdUhM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_wstd_eq::cIf_7iQRlqg3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.08f, 0, m, &cBinop_kUf3znlj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_wstd_eq::cIf_FflkraMh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_cmgx9NBb, HV_BINOP_MULTIPLY, 0, m, &cBinop_cmgx9NBb_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_cmgx9NBb, HV_BINOP_MULTIPLY, 1, m, &cBinop_cmgx9NBb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_wstd_eq::cMsg_1ak7h0zA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_E9JRZcif_sendMessage);
}

void Heavy_wstd_eq::cSystem_E9JRZcif_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ILb7W52Y_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_gOd9OE0U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_PjyqLr0E, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_4OiRSdnk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_WhPyEO3R, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_6EW6UzhD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_5RG3o5Lh, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_vMIxAGfg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_G1ysAmHZ, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_PEUMw58n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_OzTercbZ, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_2IBJBFZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Eb3Fm4hQ_sendMessage);
}

void Heavy_wstd_eq::cSystem_Eb3Fm4hQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QwhDWker, HV_BINOP_DIVIDE, 1, m, &cBinop_QwhDWker_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mFdHHdiP_sendMessage);
}

void Heavy_wstd_eq::cUnop_7wbl1zzT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_U72t86tE_sendMessage);
}

void Heavy_wstd_eq::cMsg_rUUml6ly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_7wbl1zzT_sendMessage);
}

void Heavy_wstd_eq::cBinop_U72t86tE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QwhDWker, HV_BINOP_DIVIDE, 0, m, &cBinop_QwhDWker_sendMessage);
}

void Heavy_wstd_eq::cCast_mFdHHdiP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rUUml6ly_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_QwhDWker_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eyKZK1Op, HV_BINOP_MULTIPLY, 1, m, &cBinop_eyKZK1Op_sendMessage);
}

void Heavy_wstd_eq::cBinop_eyKZK1Op_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_znIqJwPQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_p1cu9ZFE_sendMessage);
}

void Heavy_wstd_eq::cUnop_IMuEJ0CS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_nKg92UMY_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cUnop_SbbVAFwK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_RZOrYCVC_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_KMCwEjTD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_G1avSibd_sendMessage);
}

void Heavy_wstd_eq::cBinop_G1avSibd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eyKZK1Op, HV_BINOP_MULTIPLY, 0, m, &cBinop_eyKZK1Op_sendMessage);
}

void Heavy_wstd_eq::cBinop_v0NBNeob_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_a1PPkt5G_sendMessage);
}

void Heavy_wstd_eq::cBinop_a1PPkt5G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RqFwtWC1_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_BzuNBnuM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9ZHkLloh, 1, m, &cVar_9ZHkLloh_sendMessage);
}

void Heavy_wstd_eq::cVar_9ZHkLloh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nLKqRPQ7_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_aA1TdXwB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_YuFEbiOo_sendMessage);
}

void Heavy_wstd_eq::cBinop_YuFEbiOo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0rTOOH05, HV_BINOP_MULTIPLY, 1, m, &cBinop_0rTOOH05_sendMessage);
}

void Heavy_wstd_eq::cBinop_6aPx0swC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yTamDcbZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_yTamDcbZ_sendMessage);
}

void Heavy_wstd_eq::cBinop_uphfnGWi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_x4Skjfc6, HV_BINOP_MULTIPLY, 1, m, &cBinop_x4Skjfc6_sendMessage);
}

void Heavy_wstd_eq::cBinop_1d0g2CAg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7CwVeQ1x, HV_BINOP_MULTIPLY, 1, m, &cBinop_7CwVeQ1x_sendMessage);
}

void Heavy_wstd_eq::cMsg_JzLWzUVe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_eC60vYL0_sendMessage);
}

void Heavy_wstd_eq::cBinop_eC60vYL0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OBrMV5QR, HV_BINOP_MULTIPLY, 1, m, &cBinop_OBrMV5QR_sendMessage);
}

void Heavy_wstd_eq::cVar_OM7PmNz7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8VoiHu9h_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_KMCwEjTD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2U0oSLsb_sendMessage);
}

void Heavy_wstd_eq::cVar_pwYjxXwR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_v0NBNeob_sendMessage);
}

void Heavy_wstd_eq::cCast_znIqJwPQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_IMuEJ0CS_sendMessage);
}

void Heavy_wstd_eq::cCast_p1cu9ZFE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_SbbVAFwK_sendMessage);
}

void Heavy_wstd_eq::cSend_nKg92UMY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Z6Ndq3Jq_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_RZOrYCVC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WgeSZZCR_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_oCfyck5i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ZyGIg4II_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_RqFwtWC1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_r6njJluE_sendMessage);
}

void Heavy_wstd_eq::cBinop_r6njJluE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DrIJ0Q96, HV_BINOP_MULTIPLY, 1, m, &cBinop_DrIJ0Q96_sendMessage);
}

void Heavy_wstd_eq::cBinop_DrIJ0Q96_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_jEi8pKYU_sendMessage);
}

void Heavy_wstd_eq::cBinop_jEi8pKYU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_oCfyck5i_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_nLKqRPQ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_mE0NfmmH_sendMessage);
}

void Heavy_wstd_eq::cBinop_mE0NfmmH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_K7FnI81Q_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Hg606MDK_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_u67Te4UF_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aBsJYsmM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qcMS2WXc_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7vNbE19Y_sendMessage);
}

void Heavy_wstd_eq::cBinop_0rTOOH05_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gOd9OE0U_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_yTamDcbZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4OiRSdnk_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_x4Skjfc6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6EW6UzhD_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_7CwVeQ1x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vMIxAGfg_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_OBrMV5QR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PEUMw58n_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cCast_rjVvlzBA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pwYjxXwR, 1, m, &cVar_pwYjxXwR_sendMessage);
}

void Heavy_wstd_eq::cCast_AMcr6TI9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OM7PmNz7, 0, m, &cVar_OM7PmNz7_sendMessage);
}

void Heavy_wstd_eq::cCast_u67Te4UF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7CwVeQ1x, HV_BINOP_MULTIPLY, 0, m, &cBinop_7CwVeQ1x_sendMessage);
}

void Heavy_wstd_eq::cCast_K7FnI81Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_wstd_eq::cCast_aBsJYsmM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_x4Skjfc6, HV_BINOP_MULTIPLY, 0, m, &cBinop_x4Skjfc6_sendMessage);
}

void Heavy_wstd_eq::cCast_Hg606MDK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OBrMV5QR, HV_BINOP_MULTIPLY, 0, m, &cBinop_OBrMV5QR_sendMessage);
}

void Heavy_wstd_eq::cCast_7vNbE19Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0rTOOH05, HV_BINOP_MULTIPLY, 0, m, &cBinop_0rTOOH05_sendMessage);
}

void Heavy_wstd_eq::cCast_qcMS2WXc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yTamDcbZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_yTamDcbZ_sendMessage);
}

void Heavy_wstd_eq::cCast_2U0oSLsb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9ZHkLloh, 0, m, &cVar_9ZHkLloh_sendMessage);
}

void Heavy_wstd_eq::cCast_8VoiHu9h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pwYjxXwR, 0, m, &cVar_pwYjxXwR_sendMessage);
}

void Heavy_wstd_eq::cMsg_dMfrEGQd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ZBSdFStx, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_ClXdhFkM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_DhBlLOfS, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_wgXzs6kX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_t0cetnap, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_vA1PIrwN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_1jKM1RTJ, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_nfZWcWpu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_2r6UQ34S, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_7RQyF26o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_W7nOIbD8_sendMessage);
}

void Heavy_wstd_eq::cSystem_W7nOIbD8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kb82QTZv, HV_BINOP_DIVIDE, 1, m, &cBinop_kb82QTZv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rdqZW7lX_sendMessage);
}

void Heavy_wstd_eq::cUnop_QXSP58xh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_W1rX94nI_sendMessage);
}

void Heavy_wstd_eq::cMsg_7hC13U84_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_QXSP58xh_sendMessage);
}

void Heavy_wstd_eq::cBinop_W1rX94nI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kb82QTZv, HV_BINOP_DIVIDE, 0, m, &cBinop_kb82QTZv_sendMessage);
}

void Heavy_wstd_eq::cCast_rdqZW7lX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7hC13U84_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_kb82QTZv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U1TcPBAg, HV_BINOP_MULTIPLY, 1, m, &cBinop_U1TcPBAg_sendMessage);
}

void Heavy_wstd_eq::cBinop_U1TcPBAg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kVayVQb2_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BmMMMpCQ_sendMessage);
}

void Heavy_wstd_eq::cUnop_I7rzP0c0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_nWqpQGyv_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cUnop_rdw42rOg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_MGCFsoRZ_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_xu6JTw96_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_xrv3j5ic_sendMessage);
}

void Heavy_wstd_eq::cBinop_xrv3j5ic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U1TcPBAg, HV_BINOP_MULTIPLY, 0, m, &cBinop_U1TcPBAg_sendMessage);
}

void Heavy_wstd_eq::cBinop_3tMkHax6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_Uhw4JHzk_sendMessage);
}

void Heavy_wstd_eq::cBinop_Uhw4JHzk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gulxdHX9_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_TFIcJKuo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WhUnj7K8, 1, m, &cVar_WhUnj7K8_sendMessage);
}

void Heavy_wstd_eq::cVar_WhUnj7K8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2cGzCAFG_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_AVE1gIfa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_cO8gd8PA_sendMessage);
}

void Heavy_wstd_eq::cBinop_cO8gd8PA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ddrfe7cX, HV_BINOP_MULTIPLY, 1, m, &cBinop_ddrfe7cX_sendMessage);
}

void Heavy_wstd_eq::cBinop_hzEtKm98_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FZYOc0xm, HV_BINOP_MULTIPLY, 1, m, &cBinop_FZYOc0xm_sendMessage);
}

void Heavy_wstd_eq::cBinop_L4ODBZkF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vYj6X7M1, HV_BINOP_MULTIPLY, 1, m, &cBinop_vYj6X7M1_sendMessage);
}

void Heavy_wstd_eq::cBinop_2TlxrnYh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_huknT3y8, HV_BINOP_MULTIPLY, 1, m, &cBinop_huknT3y8_sendMessage);
}

void Heavy_wstd_eq::cMsg_BPxgaXWU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_aOFpx7mf_sendMessage);
}

void Heavy_wstd_eq::cBinop_aOFpx7mf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_30cfP7c7, HV_BINOP_MULTIPLY, 1, m, &cBinop_30cfP7c7_sendMessage);
}

void Heavy_wstd_eq::cVar_0vgO6XPO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ukk3QiWF_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_xu6JTw96_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HQpkAGXt_sendMessage);
}

void Heavy_wstd_eq::cVar_7bAXRiB6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_3tMkHax6_sendMessage);
}

void Heavy_wstd_eq::cCast_kVayVQb2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_I7rzP0c0_sendMessage);
}

void Heavy_wstd_eq::cCast_BmMMMpCQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_rdw42rOg_sendMessage);
}

void Heavy_wstd_eq::cSend_nWqpQGyv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_bgT2vYno_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_MGCFsoRZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_7QVuGES2_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_WX4TgThR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YduBgfRN_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_gulxdHX9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_XTMR4AJm_sendMessage);
}

void Heavy_wstd_eq::cBinop_XTMR4AJm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JTfULxjQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_JTfULxjQ_sendMessage);
}

void Heavy_wstd_eq::cBinop_JTfULxjQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_QMKeH5PH_sendMessage);
}

void Heavy_wstd_eq::cBinop_QMKeH5PH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_WX4TgThR_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_2cGzCAFG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_3JA7o8t9_sendMessage);
}

void Heavy_wstd_eq::cBinop_3JA7o8t9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bPb9GTGp_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4Dgs5VyB_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aPAV2VU2_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_J3JgKFhi_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zc9MQyjv_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zYhxgXK5_sendMessage);
}

void Heavy_wstd_eq::cBinop_ddrfe7cX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dMfrEGQd_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_FZYOc0xm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ClXdhFkM_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_vYj6X7M1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wgXzs6kX_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_huknT3y8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vA1PIrwN_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_30cfP7c7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nfZWcWpu_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cCast_8sUYRrRL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7bAXRiB6, 1, m, &cVar_7bAXRiB6_sendMessage);
}

void Heavy_wstd_eq::cCast_zlTi5RfH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0vgO6XPO, 0, m, &cVar_0vgO6XPO_sendMessage);
}

void Heavy_wstd_eq::cCast_J3JgKFhi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vYj6X7M1, HV_BINOP_MULTIPLY, 0, m, &cBinop_vYj6X7M1_sendMessage);
}

void Heavy_wstd_eq::cCast_zYhxgXK5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ddrfe7cX, HV_BINOP_MULTIPLY, 0, m, &cBinop_ddrfe7cX_sendMessage);
}

void Heavy_wstd_eq::cCast_aPAV2VU2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_huknT3y8, HV_BINOP_MULTIPLY, 0, m, &cBinop_huknT3y8_sendMessage);
}

void Heavy_wstd_eq::cCast_4Dgs5VyB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_30cfP7c7, HV_BINOP_MULTIPLY, 0, m, &cBinop_30cfP7c7_sendMessage);
}

void Heavy_wstd_eq::cCast_zc9MQyjv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FZYOc0xm, HV_BINOP_MULTIPLY, 0, m, &cBinop_FZYOc0xm_sendMessage);
}

void Heavy_wstd_eq::cCast_bPb9GTGp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_wstd_eq::cCast_HQpkAGXt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WhUnj7K8, 0, m, &cVar_WhUnj7K8_sendMessage);
}

void Heavy_wstd_eq::cCast_Ukk3QiWF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7bAXRiB6, 0, m, &cVar_7bAXRiB6_sendMessage);
}

void Heavy_wstd_eq::cMsg_Vt9KaPYI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_TJ7GUUQc, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_G7GxCVS3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_p0AND5Yy, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_T7s1V9y4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_snMtXBTZ, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_PIDX5LVO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_9OMPI0DS, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_IXLMPC8F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ehkIgxvU, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_Ev4t9BOR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_giCMxdmg_sendMessage);
}

void Heavy_wstd_eq::cSystem_giCMxdmg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_agmm1xSO, HV_BINOP_DIVIDE, 1, m, &cBinop_agmm1xSO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QxhnpozZ_sendMessage);
}

void Heavy_wstd_eq::cUnop_72gR7ooR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_8bmhMES7_sendMessage);
}

void Heavy_wstd_eq::cMsg_Aq4IDJnn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_72gR7ooR_sendMessage);
}

void Heavy_wstd_eq::cBinop_8bmhMES7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_agmm1xSO, HV_BINOP_DIVIDE, 0, m, &cBinop_agmm1xSO_sendMessage);
}

void Heavy_wstd_eq::cCast_QxhnpozZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Aq4IDJnn_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_agmm1xSO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Es18HmMB, HV_BINOP_MULTIPLY, 1, m, &cBinop_Es18HmMB_sendMessage);
}

void Heavy_wstd_eq::cBinop_Es18HmMB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sX4S9tTi_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Y0eXF2Tz_sendMessage);
}

void Heavy_wstd_eq::cUnop_FqgXHbsV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_uRw3QRDz_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cUnop_wG0YQcP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_L5KaQJtO_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_NpLkd2YD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_WzEBlCcG_sendMessage);
}

void Heavy_wstd_eq::cBinop_WzEBlCcG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Es18HmMB, HV_BINOP_MULTIPLY, 0, m, &cBinop_Es18HmMB_sendMessage);
}

void Heavy_wstd_eq::cBinop_B40YH5tu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_gxdD2sH5_sendMessage);
}

void Heavy_wstd_eq::cBinop_gxdD2sH5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CL23QDZa_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_P57jGLO8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_08T3t8O2, 1, m, &cVar_08T3t8O2_sendMessage);
}

void Heavy_wstd_eq::cVar_08T3t8O2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OV0e0qx1_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_GxeuYnFO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XO5etX6B, HV_BINOP_MULTIPLY, 1, m, &cBinop_XO5etX6B_sendMessage);
}

void Heavy_wstd_eq::cBinop_yLrnMoXp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_GxeuYnFO_sendMessage);
}

void Heavy_wstd_eq::cBinop_vq9FpjWo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_jRWAt07q_sendMessage);
}

void Heavy_wstd_eq::cBinop_jRWAt07q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zte07MMj, HV_BINOP_MULTIPLY, 1, m, &cBinop_zte07MMj_sendMessage);
}

void Heavy_wstd_eq::cBinop_YvayZ1Ho_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RU16w1bM, HV_BINOP_MULTIPLY, 1, m, &cBinop_RU16w1bM_sendMessage);
}

void Heavy_wstd_eq::cBinop_0gzuQeZy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_YvayZ1Ho_sendMessage);
}

void Heavy_wstd_eq::cBinop_FtdnMwbi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ez5qIJCs, HV_BINOP_MULTIPLY, 1, m, &cBinop_ez5qIJCs_sendMessage);
}

void Heavy_wstd_eq::cMsg_OlPOpT5I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_KpAnA9Td_sendMessage);
}

void Heavy_wstd_eq::cBinop_KpAnA9Td_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tBD1cWyA, HV_BINOP_MULTIPLY, 1, m, &cBinop_tBD1cWyA_sendMessage);
}

void Heavy_wstd_eq::cVar_qgVdsg7B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_F4KE6uDL_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_NpLkd2YD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mfoYRt3E_sendMessage);
}

void Heavy_wstd_eq::cVar_TZN4gtv3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_B40YH5tu_sendMessage);
}

void Heavy_wstd_eq::cCast_sX4S9tTi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_FqgXHbsV_sendMessage);
}

void Heavy_wstd_eq::cCast_Y0eXF2Tz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_wG0YQcP5_sendMessage);
}

void Heavy_wstd_eq::cSend_uRw3QRDz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_33E0d4rY_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_L5KaQJtO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_iNu0k2ff_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_mC2c9J4L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_rthEiND4_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_CL23QDZa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Dw1I2Tjv_sendMessage);
}

void Heavy_wstd_eq::cBinop_Dw1I2Tjv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_88DxliJP, HV_BINOP_MULTIPLY, 1, m, &cBinop_88DxliJP_sendMessage);
}

void Heavy_wstd_eq::cBinop_88DxliJP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_IESZVFIw_sendMessage);
}

void Heavy_wstd_eq::cBinop_IESZVFIw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_mC2c9J4L_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_OV0e0qx1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_SVGtrD2V_sendMessage);
}

void Heavy_wstd_eq::cBinop_SVGtrD2V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_muWnQt0K_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kmEMGlox_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WJpqqO6B_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TCtZvDaf_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UnLe5UZs_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LP6Xp4i6_sendMessage);
}

void Heavy_wstd_eq::cBinop_XO5etX6B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Vt9KaPYI_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_zte07MMj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_G7GxCVS3_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_RU16w1bM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_T7s1V9y4_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_ez5qIJCs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PIDX5LVO_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_tBD1cWyA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IXLMPC8F_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cCast_nF7pzwEd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qgVdsg7B, 0, m, &cVar_qgVdsg7B_sendMessage);
}

void Heavy_wstd_eq::cCast_6NaIXHRx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TZN4gtv3, 1, m, &cVar_TZN4gtv3_sendMessage);
}

void Heavy_wstd_eq::cCast_UnLe5UZs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zte07MMj, HV_BINOP_MULTIPLY, 0, m, &cBinop_zte07MMj_sendMessage);
}

void Heavy_wstd_eq::cCast_WJpqqO6B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ez5qIJCs, HV_BINOP_MULTIPLY, 0, m, &cBinop_ez5qIJCs_sendMessage);
}

void Heavy_wstd_eq::cCast_TCtZvDaf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RU16w1bM, HV_BINOP_MULTIPLY, 0, m, &cBinop_RU16w1bM_sendMessage);
}

void Heavy_wstd_eq::cCast_kmEMGlox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tBD1cWyA, HV_BINOP_MULTIPLY, 0, m, &cBinop_tBD1cWyA_sendMessage);
}

void Heavy_wstd_eq::cCast_muWnQt0K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_wstd_eq::cCast_LP6Xp4i6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XO5etX6B, HV_BINOP_MULTIPLY, 0, m, &cBinop_XO5etX6B_sendMessage);
}

void Heavy_wstd_eq::cCast_mfoYRt3E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_08T3t8O2, 0, m, &cVar_08T3t8O2_sendMessage);
}

void Heavy_wstd_eq::cCast_F4KE6uDL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TZN4gtv3, 0, m, &cVar_TZN4gtv3_sendMessage);
}

void Heavy_wstd_eq::cMsg_QyDrl4DH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_lv85JNTU, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_khg8hy8E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ugXoyMlg, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_KQ4sCoMG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_C39A06R9, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_hREoAJ7J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_JyEr8Y3C, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_eH9FYKy0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ja0JIiAC, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_t8PU7aV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lV6Yy9XH_sendMessage);
}

void Heavy_wstd_eq::cSystem_lV6Yy9XH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_61mmWTBu, HV_BINOP_DIVIDE, 1, m, &cBinop_61mmWTBu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BUR1JoSi_sendMessage);
}

void Heavy_wstd_eq::cUnop_pJ7hNKXu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_M5yh0meR_sendMessage);
}

void Heavy_wstd_eq::cMsg_cYffXEpi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_pJ7hNKXu_sendMessage);
}

void Heavy_wstd_eq::cBinop_M5yh0meR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_61mmWTBu, HV_BINOP_DIVIDE, 0, m, &cBinop_61mmWTBu_sendMessage);
}

void Heavy_wstd_eq::cCast_BUR1JoSi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cYffXEpi_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_61mmWTBu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vetfW3Lj, HV_BINOP_MULTIPLY, 1, m, &cBinop_vetfW3Lj_sendMessage);
}

void Heavy_wstd_eq::cBinop_vetfW3Lj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_d3e8TzRl_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DJi5ce4j_sendMessage);
}

void Heavy_wstd_eq::cUnop_G9EsTcwI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_dus0V9aJ_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cUnop_oJwhVfwj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_dwhxhi2c_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_j9ww87a8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_yUoiHv0I_sendMessage);
}

void Heavy_wstd_eq::cBinop_yUoiHv0I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vetfW3Lj, HV_BINOP_MULTIPLY, 0, m, &cBinop_vetfW3Lj_sendMessage);
}

void Heavy_wstd_eq::cBinop_PCoQsXbu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_0DFkvIGV_sendMessage);
}

void Heavy_wstd_eq::cBinop_0DFkvIGV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yGXBxkoh_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_42DQUJ1D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z7y8RPkN, HV_BINOP_MULTIPLY, 1, m, &cBinop_z7y8RPkN_sendMessage);
}

void Heavy_wstd_eq::cMsg_KAqe9174_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_XUerM4Hf_sendMessage);
}

void Heavy_wstd_eq::cBinop_XUerM4Hf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_42DQUJ1D_sendMessage);
}

void Heavy_wstd_eq::cMsg_ZA5LE6fn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_dTMRv8rA_sendMessage);
}

void Heavy_wstd_eq::cBinop_dTMRv8rA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_X1XyouYg, HV_BINOP_MULTIPLY, 1, m, &cBinop_X1XyouYg_sendMessage);
}

void Heavy_wstd_eq::cBinop_EmZdurRE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jfSy8QtO, HV_BINOP_MULTIPLY, 1, m, &cBinop_jfSy8QtO_sendMessage);
}

void Heavy_wstd_eq::cMsg_GNztKx2Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_1yCKpfpn_sendMessage);
}

void Heavy_wstd_eq::cBinop_1yCKpfpn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_EmZdurRE_sendMessage);
}

void Heavy_wstd_eq::cBinop_yfPrKNby_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FRSd138D, 1, m, &cVar_FRSd138D_sendMessage);
}

void Heavy_wstd_eq::cBinop_VgYnpMCM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_b3WPDJNn, HV_BINOP_MULTIPLY, 1, m, &cBinop_b3WPDJNn_sendMessage);
}

void Heavy_wstd_eq::cMsg_eXMT3rCy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_VwB0kAmh_sendMessage);
}

void Heavy_wstd_eq::cBinop_VwB0kAmh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_336fQNp5, HV_BINOP_MULTIPLY, 1, m, &cBinop_336fQNp5_sendMessage);
}

void Heavy_wstd_eq::cVar_FRSd138D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_602cywv9_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cVar_2ftN6oT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yVEZlQwd_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_j9ww87a8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qwnUQBzO_sendMessage);
}

void Heavy_wstd_eq::cVar_9gLw6tKp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_PCoQsXbu_sendMessage);
}

void Heavy_wstd_eq::cCast_d3e8TzRl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_G9EsTcwI_sendMessage);
}

void Heavy_wstd_eq::cCast_DJi5ce4j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_oJwhVfwj_sendMessage);
}

void Heavy_wstd_eq::cSend_dus0V9aJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_KYDt84Ro_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_dwhxhi2c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_6vAmuSge_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_LR8uBDNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_73juy3Xb_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_yGXBxkoh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_PScymFzc_sendMessage);
}

void Heavy_wstd_eq::cBinop_PScymFzc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jgSUHfZ7, HV_BINOP_MULTIPLY, 1, m, &cBinop_jgSUHfZ7_sendMessage);
}

void Heavy_wstd_eq::cBinop_jgSUHfZ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_W5kO9tke_sendMessage);
}

void Heavy_wstd_eq::cBinop_W5kO9tke_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_LR8uBDNl_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_602cywv9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_irP1Jc6e_sendMessage);
}

void Heavy_wstd_eq::cBinop_irP1Jc6e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rdkasT38_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_p5NhXmvC_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bmksnlzj_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1qzkBiaT_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EULUpuwG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JLuh3c16_sendMessage);
}

void Heavy_wstd_eq::cBinop_z7y8RPkN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QyDrl4DH_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_X1XyouYg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_khg8hy8E_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_jfSy8QtO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KQ4sCoMG_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_b3WPDJNn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hREoAJ7J_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_336fQNp5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eH9FYKy0_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cCast_AV0kg5Sl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9gLw6tKp, 1, m, &cVar_9gLw6tKp_sendMessage);
}

void Heavy_wstd_eq::cCast_mMbozybl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2ftN6oT1, 0, m, &cVar_2ftN6oT1_sendMessage);
}

void Heavy_wstd_eq::cCast_rdkasT38_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_wstd_eq::cCast_1qzkBiaT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jfSy8QtO, HV_BINOP_MULTIPLY, 0, m, &cBinop_jfSy8QtO_sendMessage);
}

void Heavy_wstd_eq::cCast_JLuh3c16_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z7y8RPkN, HV_BINOP_MULTIPLY, 0, m, &cBinop_z7y8RPkN_sendMessage);
}

void Heavy_wstd_eq::cCast_bmksnlzj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_b3WPDJNn, HV_BINOP_MULTIPLY, 0, m, &cBinop_b3WPDJNn_sendMessage);
}

void Heavy_wstd_eq::cCast_EULUpuwG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_X1XyouYg, HV_BINOP_MULTIPLY, 0, m, &cBinop_X1XyouYg_sendMessage);
}

void Heavy_wstd_eq::cCast_p5NhXmvC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_336fQNp5, HV_BINOP_MULTIPLY, 0, m, &cBinop_336fQNp5_sendMessage);
}

void Heavy_wstd_eq::cCast_qwnUQBzO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FRSd138D, 0, m, &cVar_FRSd138D_sendMessage);
}

void Heavy_wstd_eq::cCast_yVEZlQwd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9gLw6tKp, 0, m, &cVar_9gLw6tKp_sendMessage);
}

void Heavy_wstd_eq::cMsg_lkWcN5jv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_dIuHBYC7, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_5siDjt3X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_2fjRtvkO, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_1iV6aytn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_kJMyAj6v, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_BKWmPSYy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_uR2KHnk8, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_WbPuLw8L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_dEzpSIr6, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_ozZqbJOY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZzZBG79g_sendMessage);
}

void Heavy_wstd_eq::cSystem_ZzZBG79g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GseVUSKp, HV_BINOP_DIVIDE, 1, m, &cBinop_GseVUSKp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2OVXoYtT_sendMessage);
}

void Heavy_wstd_eq::cUnop_vOWYSrgo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_zXPpxnsf_sendMessage);
}

void Heavy_wstd_eq::cMsg_vDq1jxdA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_vOWYSrgo_sendMessage);
}

void Heavy_wstd_eq::cBinop_zXPpxnsf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GseVUSKp, HV_BINOP_DIVIDE, 0, m, &cBinop_GseVUSKp_sendMessage);
}

void Heavy_wstd_eq::cCast_2OVXoYtT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vDq1jxdA_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_GseVUSKp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6ynvfKp1, HV_BINOP_MULTIPLY, 1, m, &cBinop_6ynvfKp1_sendMessage);
}

void Heavy_wstd_eq::cBinop_6ynvfKp1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DqJvCG8p_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_f0QY8hUE_sendMessage);
}

void Heavy_wstd_eq::cUnop_cFXCtarV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_io1cuaQb_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cUnop_Mo1TvAOM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_QPHuHiqh_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_sKbEH2HO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_8v7E5okp_sendMessage);
}

void Heavy_wstd_eq::cBinop_8v7E5okp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6ynvfKp1, HV_BINOP_MULTIPLY, 0, m, &cBinop_6ynvfKp1_sendMessage);
}

void Heavy_wstd_eq::cBinop_cbLOl9Ag_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_kFG1VVvx_sendMessage);
}

void Heavy_wstd_eq::cBinop_kFG1VVvx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MksGewsM_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_uYQFwkzW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sRPH2vAJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_sRPH2vAJ_sendMessage);
}

void Heavy_wstd_eq::cMsg_omkxy7mg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_RQVKvZOD_sendMessage);
}

void Heavy_wstd_eq::cBinop_RQVKvZOD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_uYQFwkzW_sendMessage);
}

void Heavy_wstd_eq::cMsg_wjZha833_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_3W4BLhmJ_sendMessage);
}

void Heavy_wstd_eq::cBinop_3W4BLhmJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OKBPZVea, HV_BINOP_MULTIPLY, 1, m, &cBinop_OKBPZVea_sendMessage);
}

void Heavy_wstd_eq::cBinop_NOhPX1MP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LWK4Tgnw, HV_BINOP_MULTIPLY, 1, m, &cBinop_LWK4Tgnw_sendMessage);
}

void Heavy_wstd_eq::cMsg_NEtL5DZ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_SHdQyfRu_sendMessage);
}

void Heavy_wstd_eq::cBinop_SHdQyfRu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_NOhPX1MP_sendMessage);
}

void Heavy_wstd_eq::cBinop_XfajgK7U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Bp5tj4ok, 1, m, &cVar_Bp5tj4ok_sendMessage);
}

void Heavy_wstd_eq::cBinop_HBPGjuH3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9gZQVCSS, HV_BINOP_MULTIPLY, 1, m, &cBinop_9gZQVCSS_sendMessage);
}

void Heavy_wstd_eq::cMsg_GRBUwJ1t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_Xe3ZUwum_sendMessage);
}

void Heavy_wstd_eq::cBinop_Xe3ZUwum_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qLJRXd8t, HV_BINOP_MULTIPLY, 1, m, &cBinop_qLJRXd8t_sendMessage);
}

void Heavy_wstd_eq::cVar_Bp5tj4ok_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kLV8YgYO_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cVar_wtME6Uov_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YtM69X6F_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_sKbEH2HO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yEkKfpa5_sendMessage);
}

void Heavy_wstd_eq::cVar_qJx01nPl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_cbLOl9Ag_sendMessage);
}

void Heavy_wstd_eq::cCast_f0QY8hUE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_Mo1TvAOM_sendMessage);
}

void Heavy_wstd_eq::cCast_DqJvCG8p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_cFXCtarV_sendMessage);
}

void Heavy_wstd_eq::cSend_io1cuaQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_nNBLp2Nq_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_QPHuHiqh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4cFShlWc_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_XgZrrtP1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_bTtX2kwY_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_MksGewsM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_bnnggSFb_sendMessage);
}

void Heavy_wstd_eq::cBinop_bnnggSFb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZQEsxKv0, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZQEsxKv0_sendMessage);
}

void Heavy_wstd_eq::cBinop_ZQEsxKv0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_vKefWuXi_sendMessage);
}

void Heavy_wstd_eq::cBinop_vKefWuXi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_XgZrrtP1_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_kLV8YgYO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_0fXq7GZX_sendMessage);
}

void Heavy_wstd_eq::cBinop_0fXq7GZX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_evla66Tl_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZOzTfJVz_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5WL9FQUS_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_y4cg8yUz_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RX3IYzPK_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tzi7W8Mx_sendMessage);
}

void Heavy_wstd_eq::cBinop_sRPH2vAJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lkWcN5jv_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_OKBPZVea_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5siDjt3X_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_LWK4Tgnw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1iV6aytn_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_9gZQVCSS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BKWmPSYy_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_qLJRXd8t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WbPuLw8L_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cCast_8ziKCXCy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qJx01nPl, 1, m, &cVar_qJx01nPl_sendMessage);
}

void Heavy_wstd_eq::cCast_fgdzIA2D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wtME6Uov, 0, m, &cVar_wtME6Uov_sendMessage);
}

void Heavy_wstd_eq::cCast_y4cg8yUz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LWK4Tgnw, HV_BINOP_MULTIPLY, 0, m, &cBinop_LWK4Tgnw_sendMessage);
}

void Heavy_wstd_eq::cCast_5WL9FQUS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9gZQVCSS, HV_BINOP_MULTIPLY, 0, m, &cBinop_9gZQVCSS_sendMessage);
}

void Heavy_wstd_eq::cCast_RX3IYzPK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OKBPZVea, HV_BINOP_MULTIPLY, 0, m, &cBinop_OKBPZVea_sendMessage);
}

void Heavy_wstd_eq::cCast_evla66Tl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_wstd_eq::cCast_ZOzTfJVz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qLJRXd8t, HV_BINOP_MULTIPLY, 0, m, &cBinop_qLJRXd8t_sendMessage);
}

void Heavy_wstd_eq::cCast_tzi7W8Mx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sRPH2vAJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_sRPH2vAJ_sendMessage);
}

void Heavy_wstd_eq::cCast_yEkKfpa5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Bp5tj4ok, 0, m, &cVar_Bp5tj4ok_sendMessage);
}

void Heavy_wstd_eq::cCast_YtM69X6F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qJx01nPl, 0, m, &cVar_qJx01nPl_sendMessage);
}

void Heavy_wstd_eq::cMsg_Spq2liNo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_JIZCItgG, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_aBmjJ6ma_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_QErnWAu2, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_lNca3z7Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_mouepVdo, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_kk1ENU33_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_1OOQyxGa, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_kFfFzVUv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_0P2v0WAj, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_ArjhF5VC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FJYF6HJU_sendMessage);
}

void Heavy_wstd_eq::cSystem_FJYF6HJU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lliUJDoF, HV_BINOP_DIVIDE, 1, m, &cBinop_lliUJDoF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fqpqde5R_sendMessage);
}

void Heavy_wstd_eq::cUnop_Dpjnj4Sj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_Nwk0eZo3_sendMessage);
}

void Heavy_wstd_eq::cMsg_SUeLJi4K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_Dpjnj4Sj_sendMessage);
}

void Heavy_wstd_eq::cBinop_Nwk0eZo3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lliUJDoF, HV_BINOP_DIVIDE, 0, m, &cBinop_lliUJDoF_sendMessage);
}

void Heavy_wstd_eq::cCast_fqpqde5R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SUeLJi4K_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_lliUJDoF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eaRXXP0N, HV_BINOP_MULTIPLY, 1, m, &cBinop_eaRXXP0N_sendMessage);
}

void Heavy_wstd_eq::cBinop_eaRXXP0N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lX1blKp7_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xIT6A4k2_sendMessage);
}

void Heavy_wstd_eq::cUnop_cfbSAjB2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_7rnNwCcK_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cUnop_Uptd3JP4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Q9PQ47UH_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_I3eDewuF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_wkja8TTC_sendMessage);
}

void Heavy_wstd_eq::cBinop_wkja8TTC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eaRXXP0N, HV_BINOP_MULTIPLY, 0, m, &cBinop_eaRXXP0N_sendMessage);
}

void Heavy_wstd_eq::cBinop_pDH2enEc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_Yom72ulV_sendMessage);
}

void Heavy_wstd_eq::cBinop_Yom72ulV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WFC4z5JI_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_Bd8LIp7Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FZcH6v8s, 1, m, &cVar_FZcH6v8s_sendMessage);
}

void Heavy_wstd_eq::cVar_FZcH6v8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TBSUTEJW_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_mH1z8Fa1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_T4MDLMdE, HV_BINOP_MULTIPLY, 1, m, &cBinop_T4MDLMdE_sendMessage);
}

void Heavy_wstd_eq::cBinop_ZfZvgvJq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_mH1z8Fa1_sendMessage);
}

void Heavy_wstd_eq::cBinop_SWzHe0Gf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_N3KcFZCz_sendMessage);
}

void Heavy_wstd_eq::cBinop_N3KcFZCz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZWWJrmok, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZWWJrmok_sendMessage);
}

void Heavy_wstd_eq::cBinop_J595YgBh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y1XeIA30, HV_BINOP_MULTIPLY, 1, m, &cBinop_Y1XeIA30_sendMessage);
}

void Heavy_wstd_eq::cBinop_mVYuwhiF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_J595YgBh_sendMessage);
}

void Heavy_wstd_eq::cBinop_7gQCGeLk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HoEhsdnl, HV_BINOP_MULTIPLY, 1, m, &cBinop_HoEhsdnl_sendMessage);
}

void Heavy_wstd_eq::cMsg_3JEObmNQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_WDA06bZW_sendMessage);
}

void Heavy_wstd_eq::cBinop_WDA06bZW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n6tDLTbH, HV_BINOP_MULTIPLY, 1, m, &cBinop_n6tDLTbH_sendMessage);
}

void Heavy_wstd_eq::cVar_UHJrWd3R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_71D8icJr_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_I3eDewuF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7vOIJENI_sendMessage);
}

void Heavy_wstd_eq::cVar_0pVaJXSZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_pDH2enEc_sendMessage);
}

void Heavy_wstd_eq::cCast_xIT6A4k2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_Uptd3JP4_sendMessage);
}

void Heavy_wstd_eq::cCast_lX1blKp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_cfbSAjB2_sendMessage);
}

void Heavy_wstd_eq::cSend_7rnNwCcK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_zHCsvsj9_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_Q9PQ47UH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_nm3v15OR_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_SwDXXWyV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Mq44tTwd_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_WFC4z5JI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_sGpkAwtp_sendMessage);
}

void Heavy_wstd_eq::cBinop_sGpkAwtp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Gi5LFuwg, HV_BINOP_MULTIPLY, 1, m, &cBinop_Gi5LFuwg_sendMessage);
}

void Heavy_wstd_eq::cBinop_Gi5LFuwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_rjObLqEz_sendMessage);
}

void Heavy_wstd_eq::cBinop_rjObLqEz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_SwDXXWyV_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_TBSUTEJW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_hJcHtW5H_sendMessage);
}

void Heavy_wstd_eq::cBinop_hJcHtW5H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QYKhs0dQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nuGhA0Jd_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZKaNWAZ5_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LqAlhT1p_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mBbdZYD3_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cC2jtPEo_sendMessage);
}

void Heavy_wstd_eq::cBinop_T4MDLMdE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Spq2liNo_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_ZWWJrmok_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aBmjJ6ma_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_Y1XeIA30_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lNca3z7Q_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_HoEhsdnl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kk1ENU33_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_n6tDLTbH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kFfFzVUv_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cCast_pJwrEtQf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0pVaJXSZ, 1, m, &cVar_0pVaJXSZ_sendMessage);
}

void Heavy_wstd_eq::cCast_P3vt7JkS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UHJrWd3R, 0, m, &cVar_UHJrWd3R_sendMessage);
}

void Heavy_wstd_eq::cCast_cC2jtPEo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_T4MDLMdE, HV_BINOP_MULTIPLY, 0, m, &cBinop_T4MDLMdE_sendMessage);
}

void Heavy_wstd_eq::cCast_mBbdZYD3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZWWJrmok, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZWWJrmok_sendMessage);
}

void Heavy_wstd_eq::cCast_nuGhA0Jd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n6tDLTbH, HV_BINOP_MULTIPLY, 0, m, &cBinop_n6tDLTbH_sendMessage);
}

void Heavy_wstd_eq::cCast_ZKaNWAZ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HoEhsdnl, HV_BINOP_MULTIPLY, 0, m, &cBinop_HoEhsdnl_sendMessage);
}

void Heavy_wstd_eq::cCast_LqAlhT1p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y1XeIA30, HV_BINOP_MULTIPLY, 0, m, &cBinop_Y1XeIA30_sendMessage);
}

void Heavy_wstd_eq::cCast_QYKhs0dQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_wstd_eq::cCast_7vOIJENI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FZcH6v8s, 0, m, &cVar_FZcH6v8s_sendMessage);
}

void Heavy_wstd_eq::cCast_71D8icJr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0pVaJXSZ, 0, m, &cVar_0pVaJXSZ_sendMessage);
}

void Heavy_wstd_eq::cMsg_Lt8u5POv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_CxcHIV8W, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_QAz2QFS9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_wcAHchiR, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_FZo0NUjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_AaO6zPYS, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_1xzTDJ1f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_PLF4KN1h, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_95eKnUBA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_8WloziL8, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_dwO3qcuk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yd1Hy8DX_sendMessage);
}

void Heavy_wstd_eq::cSystem_yd1Hy8DX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_20Q776bT, HV_BINOP_DIVIDE, 1, m, &cBinop_20Q776bT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Y1ZQKVQl_sendMessage);
}

void Heavy_wstd_eq::cUnop_AZk0OR9f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_QQLlEaHh_sendMessage);
}

void Heavy_wstd_eq::cMsg_ceFo6tIy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_AZk0OR9f_sendMessage);
}

void Heavy_wstd_eq::cBinop_QQLlEaHh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_20Q776bT, HV_BINOP_DIVIDE, 0, m, &cBinop_20Q776bT_sendMessage);
}

void Heavy_wstd_eq::cCast_Y1ZQKVQl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ceFo6tIy_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_20Q776bT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hXRt7dRo, HV_BINOP_MULTIPLY, 1, m, &cBinop_hXRt7dRo_sendMessage);
}

void Heavy_wstd_eq::cBinop_hXRt7dRo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PlZup5xf_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TGyx4JkD_sendMessage);
}

void Heavy_wstd_eq::cUnop_IpUAOc0W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_rvcIphXt_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cUnop_5izwryIK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_VZiMMI7A_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_TQpS7fqK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_jciQKjfP_sendMessage);
}

void Heavy_wstd_eq::cBinop_jciQKjfP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hXRt7dRo, HV_BINOP_MULTIPLY, 0, m, &cBinop_hXRt7dRo_sendMessage);
}

void Heavy_wstd_eq::cBinop_zeUMJ89Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_X0AXsnk1_sendMessage);
}

void Heavy_wstd_eq::cBinop_X0AXsnk1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DACZTtY2_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_WI0lO5R6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XXAcbo4Y, 1, m, &cVar_XXAcbo4Y_sendMessage);
}

void Heavy_wstd_eq::cVar_XXAcbo4Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fBYstH2u_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_yD4eigky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_upjjCyBt_sendMessage);
}

void Heavy_wstd_eq::cBinop_upjjCyBt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZqvOwIz3, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZqvOwIz3_sendMessage);
}

void Heavy_wstd_eq::cBinop_SzHVyKpN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Fb7hneay, HV_BINOP_MULTIPLY, 1, m, &cBinop_Fb7hneay_sendMessage);
}

void Heavy_wstd_eq::cBinop_rP16iscJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Yg6vVsH2, HV_BINOP_MULTIPLY, 1, m, &cBinop_Yg6vVsH2_sendMessage);
}

void Heavy_wstd_eq::cBinop_RZIIgPvT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lv5SsGBZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_lv5SsGBZ_sendMessage);
}

void Heavy_wstd_eq::cMsg_rUWulaA7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_ifPg3C9f_sendMessage);
}

void Heavy_wstd_eq::cBinop_ifPg3C9f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SHMo3w51, HV_BINOP_MULTIPLY, 1, m, &cBinop_SHMo3w51_sendMessage);
}

void Heavy_wstd_eq::cVar_LrDL1BTD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_towbOWXe_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_TQpS7fqK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZQ9iEFPu_sendMessage);
}

void Heavy_wstd_eq::cVar_28ggcQBe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_zeUMJ89Q_sendMessage);
}

void Heavy_wstd_eq::cCast_PlZup5xf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_IpUAOc0W_sendMessage);
}

void Heavy_wstd_eq::cCast_TGyx4JkD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_5izwryIK_sendMessage);
}

void Heavy_wstd_eq::cSend_rvcIphXt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_n2oVsFbE_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_VZiMMI7A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2xlVqp3A_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_UumiEvyf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_SfXKgWyS_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_DACZTtY2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_mz6EUHWu_sendMessage);
}

void Heavy_wstd_eq::cBinop_mz6EUHWu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SAfHMsrP, HV_BINOP_MULTIPLY, 1, m, &cBinop_SAfHMsrP_sendMessage);
}

void Heavy_wstd_eq::cBinop_SAfHMsrP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_ixjoz33e_sendMessage);
}

void Heavy_wstd_eq::cBinop_ixjoz33e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_UumiEvyf_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_fBYstH2u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ydlhBiXZ_sendMessage);
}

void Heavy_wstd_eq::cBinop_ydlhBiXZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QINCp338_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BsfKjTAd_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MwsxAZmJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1hylKtXz_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YlYAXW2J_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kpgsVE2H_sendMessage);
}

void Heavy_wstd_eq::cBinop_ZqvOwIz3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Lt8u5POv_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_Fb7hneay_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QAz2QFS9_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_Yg6vVsH2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FZo0NUjZ_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_lv5SsGBZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1xzTDJ1f_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_SHMo3w51_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_95eKnUBA_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cCast_ZfxYft5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_28ggcQBe, 1, m, &cVar_28ggcQBe_sendMessage);
}

void Heavy_wstd_eq::cCast_9NoHXEuB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LrDL1BTD, 0, m, &cVar_LrDL1BTD_sendMessage);
}

void Heavy_wstd_eq::cCast_kpgsVE2H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZqvOwIz3, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZqvOwIz3_sendMessage);
}

void Heavy_wstd_eq::cCast_MwsxAZmJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lv5SsGBZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_lv5SsGBZ_sendMessage);
}

void Heavy_wstd_eq::cCast_YlYAXW2J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Fb7hneay, HV_BINOP_MULTIPLY, 0, m, &cBinop_Fb7hneay_sendMessage);
}

void Heavy_wstd_eq::cCast_BsfKjTAd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SHMo3w51, HV_BINOP_MULTIPLY, 0, m, &cBinop_SHMo3w51_sendMessage);
}

void Heavy_wstd_eq::cCast_1hylKtXz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Yg6vVsH2, HV_BINOP_MULTIPLY, 0, m, &cBinop_Yg6vVsH2_sendMessage);
}

void Heavy_wstd_eq::cCast_QINCp338_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_wstd_eq::cCast_ZQ9iEFPu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XXAcbo4Y, 0, m, &cVar_XXAcbo4Y_sendMessage);
}

void Heavy_wstd_eq::cCast_towbOWXe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_28ggcQBe, 0, m, &cVar_28ggcQBe_sendMessage);
}

void Heavy_wstd_eq::cMsg_qtNtC3Jw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_kc5oHDBt, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_Vg4SNdcH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_UUKTXyyf, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_4PyIh5Al_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_MV2J712n, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_wxv7EYe8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_HJ9AyKrd, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_Y7Mbudq5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Y1P2AAAW, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_c3asxNRo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QkLid4i0_sendMessage);
}

void Heavy_wstd_eq::cSystem_QkLid4i0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sl3MCOPi, HV_BINOP_DIVIDE, 1, m, &cBinop_Sl3MCOPi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_c5wRQMme_sendMessage);
}

void Heavy_wstd_eq::cUnop_sbgwj3n2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_GspFLzqB_sendMessage);
}

void Heavy_wstd_eq::cMsg_XVLFJk21_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_sbgwj3n2_sendMessage);
}

void Heavy_wstd_eq::cBinop_GspFLzqB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sl3MCOPi, HV_BINOP_DIVIDE, 0, m, &cBinop_Sl3MCOPi_sendMessage);
}

void Heavy_wstd_eq::cCast_c5wRQMme_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XVLFJk21_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_Sl3MCOPi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NFAivrSE, HV_BINOP_MULTIPLY, 1, m, &cBinop_NFAivrSE_sendMessage);
}

void Heavy_wstd_eq::cBinop_NFAivrSE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mRk2aUJt_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pn4uMMvL_sendMessage);
}

void Heavy_wstd_eq::cUnop_1TspRWUq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_VMROJup1_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cUnop_pKebbI6x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_IZLyWNgP_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_prm12ebc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_e3bZI8UI_sendMessage);
}

void Heavy_wstd_eq::cBinop_e3bZI8UI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NFAivrSE, HV_BINOP_MULTIPLY, 0, m, &cBinop_NFAivrSE_sendMessage);
}

void Heavy_wstd_eq::cBinop_DvCT8C3C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_uL6yeVlR_sendMessage);
}

void Heavy_wstd_eq::cBinop_uL6yeVlR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_guYX5yjj_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_LdtRDBTd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RBJJEh3g, 1, m, &cVar_RBJJEh3g_sendMessage);
}

void Heavy_wstd_eq::cVar_RBJJEh3g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3WeyeKtW_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_WCHnJOVY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_Q0IVFkz8_sendMessage);
}

void Heavy_wstd_eq::cBinop_Q0IVFkz8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qBt6Yn70, HV_BINOP_MULTIPLY, 1, m, &cBinop_qBt6Yn70_sendMessage);
}

void Heavy_wstd_eq::cBinop_o8Pwxec3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5RraMR12, HV_BINOP_MULTIPLY, 1, m, &cBinop_5RraMR12_sendMessage);
}

void Heavy_wstd_eq::cBinop_ypC3c8Zh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W318RAO4, HV_BINOP_MULTIPLY, 1, m, &cBinop_W318RAO4_sendMessage);
}

void Heavy_wstd_eq::cBinop_ulwUaAJA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VmGVj2Zk, HV_BINOP_MULTIPLY, 1, m, &cBinop_VmGVj2Zk_sendMessage);
}

void Heavy_wstd_eq::cMsg_wUhNmgs6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_KihO6EJF_sendMessage);
}

void Heavy_wstd_eq::cBinop_KihO6EJF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iR8TFkN2, HV_BINOP_MULTIPLY, 1, m, &cBinop_iR8TFkN2_sendMessage);
}

void Heavy_wstd_eq::cVar_Y9I5ZBZD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9NDXk2Vq_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_prm12ebc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_v5zdrg4g_sendMessage);
}

void Heavy_wstd_eq::cVar_ftcH9VFt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_DvCT8C3C_sendMessage);
}

void Heavy_wstd_eq::cCast_mRk2aUJt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_1TspRWUq_sendMessage);
}

void Heavy_wstd_eq::cCast_pn4uMMvL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_pKebbI6x_sendMessage);
}

void Heavy_wstd_eq::cSend_VMROJup1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_nlps4aOb_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_IZLyWNgP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Ut0X5B68_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_KMRaOxtG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WNsvIoQ6_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_guYX5yjj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_bFZYtQ71_sendMessage);
}

void Heavy_wstd_eq::cBinop_bFZYtQ71_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nHyDxMcg, HV_BINOP_MULTIPLY, 1, m, &cBinop_nHyDxMcg_sendMessage);
}

void Heavy_wstd_eq::cBinop_nHyDxMcg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_acCL2tPc_sendMessage);
}

void Heavy_wstd_eq::cBinop_acCL2tPc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_KMRaOxtG_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_3WeyeKtW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_e28oy6ks_sendMessage);
}

void Heavy_wstd_eq::cBinop_e28oy6ks_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6t2lspNr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BfnfwwHE_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cKQRhZnq_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cE99vFy8_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2bJeoN2L_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nysAZZF9_sendMessage);
}

void Heavy_wstd_eq::cBinop_qBt6Yn70_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qtNtC3Jw_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_5RraMR12_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Vg4SNdcH_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_W318RAO4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4PyIh5Al_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_VmGVj2Zk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wxv7EYe8_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_iR8TFkN2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Y7Mbudq5_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cCast_LInclhB9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ftcH9VFt, 1, m, &cVar_ftcH9VFt_sendMessage);
}

void Heavy_wstd_eq::cCast_uQxwnCLR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Y9I5ZBZD, 0, m, &cVar_Y9I5ZBZD_sendMessage);
}

void Heavy_wstd_eq::cCast_nysAZZF9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qBt6Yn70, HV_BINOP_MULTIPLY, 0, m, &cBinop_qBt6Yn70_sendMessage);
}

void Heavy_wstd_eq::cCast_6t2lspNr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_wstd_eq::cCast_cKQRhZnq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VmGVj2Zk, HV_BINOP_MULTIPLY, 0, m, &cBinop_VmGVj2Zk_sendMessage);
}

void Heavy_wstd_eq::cCast_BfnfwwHE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iR8TFkN2, HV_BINOP_MULTIPLY, 0, m, &cBinop_iR8TFkN2_sendMessage);
}

void Heavy_wstd_eq::cCast_2bJeoN2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5RraMR12, HV_BINOP_MULTIPLY, 0, m, &cBinop_5RraMR12_sendMessage);
}

void Heavy_wstd_eq::cCast_cE99vFy8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W318RAO4, HV_BINOP_MULTIPLY, 0, m, &cBinop_W318RAO4_sendMessage);
}

void Heavy_wstd_eq::cCast_v5zdrg4g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RBJJEh3g, 0, m, &cVar_RBJJEh3g_sendMessage);
}

void Heavy_wstd_eq::cCast_9NDXk2Vq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ftcH9VFt, 0, m, &cVar_ftcH9VFt_sendMessage);
}

void Heavy_wstd_eq::cBinop_YBbGFzgy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_UvPtWeZ8, 0, m, &cIf_UvPtWeZ8_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_cNfAki9G, 0, m, &cIf_cNfAki9G_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 1.0f, 0, m, &cBinop_q4NoOT8n_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 1.0f, 0, m, &cBinop_o17r0p83_sendMessage);
}

void Heavy_wstd_eq::cBinop_q4NoOT8n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_UvPtWeZ8, 1, m, &cIf_UvPtWeZ8_sendMessage);
}

void Heavy_wstd_eq::cBinop_o17r0p83_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_cNfAki9G, 1, m, &cIf_cNfAki9G_sendMessage);
}

void Heavy_wstd_eq::cBinop_fW7ZkYKw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_331DZIFI, m);
}

void Heavy_wstd_eq::cBinop_AGlzsz0n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BA2AjRIa, 0, m, &cIf_BA2AjRIa_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_jnbuBru8, 0, m, &cIf_jnbuBru8_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 1.0f, 0, m, &cBinop_uskEN2LK_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 1.0f, 0, m, &cBinop_R32dtesK_sendMessage);
}

void Heavy_wstd_eq::cBinop_uskEN2LK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BA2AjRIa, 1, m, &cIf_BA2AjRIa_sendMessage);
}

void Heavy_wstd_eq::cBinop_R32dtesK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_jnbuBru8, 1, m, &cIf_jnbuBru8_sendMessage);
}

void Heavy_wstd_eq::cBinop_11CKdUhM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Gbdsmap3, m);
}

void Heavy_wstd_eq::cBinop_Sh5aINBH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_7iQRlqg3, 0, m, &cIf_7iQRlqg3_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_FflkraMh, 0, m, &cIf_FflkraMh_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 1.0f, 0, m, &cBinop_ZUGxSl8X_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 1.0f, 0, m, &cBinop_BFhPLhwW_sendMessage);
}

void Heavy_wstd_eq::cBinop_ZUGxSl8X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_7iQRlqg3, 1, m, &cIf_7iQRlqg3_sendMessage);
}

void Heavy_wstd_eq::cBinop_BFhPLhwW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_FflkraMh, 1, m, &cIf_FflkraMh_sendMessage);
}

void Heavy_wstd_eq::cBinop_cmgx9NBb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.08f, 0, m, &cBinop_kUf3znlj_sendMessage);
}

void Heavy_wstd_eq::cSend_ILb7W52Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DpXKtl7J_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_kUf3znlj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_k6PyfFD5, m);
}

void Heavy_wstd_eq::cMsg_F7BfhXE1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_RYOuD3Q5, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_WFgeFQAs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_PdYbzBRQ, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_Rh1etC8t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_7pUpOcxF, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_3hmsuQkr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_DlsYGLDY, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_yAuXPDNx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2LjLcXms_sendMessage);
}

void Heavy_wstd_eq::cSystem_2LjLcXms_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XVzAST01, HV_BINOP_DIVIDE, 1, m, &cBinop_XVzAST01_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KhGHF8DB_sendMessage);
}

void Heavy_wstd_eq::cUnop_kf0Trjne_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_p977TQOA_sendMessage);
}

void Heavy_wstd_eq::cMsg_cxeGJN98_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_kf0Trjne_sendMessage);
}

void Heavy_wstd_eq::cBinop_p977TQOA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XVzAST01, HV_BINOP_DIVIDE, 0, m, &cBinop_XVzAST01_sendMessage);
}

void Heavy_wstd_eq::cCast_KhGHF8DB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cxeGJN98_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_XVzAST01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_r4Uk3q7Y, HV_BINOP_MULTIPLY, 1, m, &cBinop_r4Uk3q7Y_sendMessage);
}

void Heavy_wstd_eq::cBinop_r4Uk3q7Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Zhqa688K_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uz4a29vd_sendMessage);
}

void Heavy_wstd_eq::cUnop_d29VkaM3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_PWcK3cdd_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cUnop_GuNzLpv9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_iLQfDkoC_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_XEvumzI3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_iFMlbbUa_sendMessage);
}

void Heavy_wstd_eq::cBinop_iFMlbbUa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_r4Uk3q7Y, HV_BINOP_MULTIPLY, 0, m, &cBinop_r4Uk3q7Y_sendMessage);
}

void Heavy_wstd_eq::cBinop_feaAAyKO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_gPyECmsQ_sendMessage);
}

void Heavy_wstd_eq::cBinop_gPyECmsQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_66XwiSbl_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_WLHYsnu4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mQfZcSZ8, HV_BINOP_MULTIPLY, 1, m, &cBinop_mQfZcSZ8_sendMessage);
}

void Heavy_wstd_eq::cBinop_Aca3QYak_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2Pcwgy44, 1, m, &cVar_2Pcwgy44_sendMessage);
}

void Heavy_wstd_eq::cBinop_KM2uehSJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_B4N8ZFqA, HV_BINOP_MULTIPLY, 1, m, &cBinop_B4N8ZFqA_sendMessage);
}

void Heavy_wstd_eq::cMsg_omLrhg5v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_nB9PSYcB_sendMessage);
}

void Heavy_wstd_eq::cBinop_nB9PSYcB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y8HtCPeZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_y8HtCPeZ_sendMessage);
}

void Heavy_wstd_eq::cVar_2Pcwgy44_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CGzq3OPQ_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cVar_kOHE8oTl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kvDHMeAK_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_XEvumzI3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aIgpJzwe_sendMessage);
}

void Heavy_wstd_eq::cVar_0iINIqik_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_feaAAyKO_sendMessage);
}

void Heavy_wstd_eq::cCast_Zhqa688K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_d29VkaM3_sendMessage);
}

void Heavy_wstd_eq::cCast_uz4a29vd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_GuNzLpv9_sendMessage);
}

void Heavy_wstd_eq::cSend_PWcK3cdd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_N6KwVPR4_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_iLQfDkoC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_e4xZa6W7_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_DCnmFPlr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4VhP27dD_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_66XwiSbl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_pNs9J03D_sendMessage);
}

void Heavy_wstd_eq::cBinop_pNs9J03D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FIw8K2uG, HV_BINOP_MULTIPLY, 1, m, &cBinop_FIw8K2uG_sendMessage);
}

void Heavy_wstd_eq::cBinop_FIw8K2uG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_ORvZ6RfQ_sendMessage);
}

void Heavy_wstd_eq::cBinop_ORvZ6RfQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_DCnmFPlr_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_CGzq3OPQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_nZvIeI5U_sendMessage);
}

void Heavy_wstd_eq::cBinop_nZvIeI5U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jy2te60H_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UT1CtVfd_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KpF16qZ7_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BI05pSI4_sendMessage);
}

void Heavy_wstd_eq::cBinop_qsU3nQFg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_F7BfhXE1_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_mQfZcSZ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WFgeFQAs_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_B4N8ZFqA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Rh1etC8t_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_y8HtCPeZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3hmsuQkr_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cCast_EMbENKFE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kOHE8oTl, 0, m, &cVar_kOHE8oTl_sendMessage);
}

void Heavy_wstd_eq::cCast_lKG6QN5x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0iINIqik, 1, m, &cVar_0iINIqik_sendMessage);
}

void Heavy_wstd_eq::cCast_kvDHMeAK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0iINIqik, 0, m, &cVar_0iINIqik_sendMessage);
}

void Heavy_wstd_eq::cCast_aIgpJzwe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2Pcwgy44, 0, m, &cVar_2Pcwgy44_sendMessage);
}

void Heavy_wstd_eq::cCast_BI05pSI4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qsU3nQFg, HV_BINOP_MULTIPLY, 0, m, &cBinop_qsU3nQFg_sendMessage);
}

void Heavy_wstd_eq::cCast_KpF16qZ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mQfZcSZ8, HV_BINOP_MULTIPLY, 0, m, &cBinop_mQfZcSZ8_sendMessage);
}

void Heavy_wstd_eq::cCast_UT1CtVfd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_B4N8ZFqA, HV_BINOP_MULTIPLY, 0, m, &cBinop_B4N8ZFqA_sendMessage);
}

void Heavy_wstd_eq::cCast_jy2te60H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y8HtCPeZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_y8HtCPeZ_sendMessage);
}

void Heavy_wstd_eq::cMsg_QpEX9eje_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_1RKzYP4D, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_E1opgaqd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_2jjh3cna, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_jJ2rkFlF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_H5JewrOc, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_y1Bnrgbc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_NbX7M5TN, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_9utkxPsn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_q34UGJYK, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_DkIPQI8K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YG7jgtPs_sendMessage);
}

void Heavy_wstd_eq::cSystem_YG7jgtPs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UvJw8thr, HV_BINOP_DIVIDE, 1, m, &cBinop_UvJw8thr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qDRTy2os_sendMessage);
}

void Heavy_wstd_eq::cUnop_oCkaQ4EE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_XL2Ca2XC_sendMessage);
}

void Heavy_wstd_eq::cMsg_G4sh1S8B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_oCkaQ4EE_sendMessage);
}

void Heavy_wstd_eq::cBinop_XL2Ca2XC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UvJw8thr, HV_BINOP_DIVIDE, 0, m, &cBinop_UvJw8thr_sendMessage);
}

void Heavy_wstd_eq::cCast_qDRTy2os_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_G4sh1S8B_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_UvJw8thr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VwSTipcM, HV_BINOP_MULTIPLY, 1, m, &cBinop_VwSTipcM_sendMessage);
}

void Heavy_wstd_eq::cBinop_VwSTipcM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_u4semES9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CmBOjU5w_sendMessage);
}

void Heavy_wstd_eq::cUnop_di6A288r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_dZiECMYY_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cUnop_sxYTqrCO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_daRCber9_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_U7lUAwkq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_HjO3Efjt_sendMessage);
}

void Heavy_wstd_eq::cBinop_HjO3Efjt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VwSTipcM, HV_BINOP_MULTIPLY, 0, m, &cBinop_VwSTipcM_sendMessage);
}

void Heavy_wstd_eq::cBinop_g2xsoBKq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_OBmwXyxu_sendMessage);
}

void Heavy_wstd_eq::cBinop_OBmwXyxu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Wvf2SGG5_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_N1NvTrwN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J06v5yYD, HV_BINOP_MULTIPLY, 1, m, &cBinop_J06v5yYD_sendMessage);
}

void Heavy_wstd_eq::cMsg_TCpPBKxV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_y3QJ3tLF_sendMessage);
}

void Heavy_wstd_eq::cBinop_y3QJ3tLF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_N1NvTrwN_sendMessage);
}

void Heavy_wstd_eq::cMsg_PTU8H6lW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_otn2cxrU_sendMessage);
}

void Heavy_wstd_eq::cBinop_otn2cxrU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rewiAiEL, HV_BINOP_MULTIPLY, 1, m, &cBinop_rewiAiEL_sendMessage);
}

void Heavy_wstd_eq::cBinop_XrRdlv4I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GSacWdsX, HV_BINOP_MULTIPLY, 1, m, &cBinop_GSacWdsX_sendMessage);
}

void Heavy_wstd_eq::cMsg_paxIuIK5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_4T6lNm0F_sendMessage);
}

void Heavy_wstd_eq::cBinop_4T6lNm0F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_XrRdlv4I_sendMessage);
}

void Heavy_wstd_eq::cBinop_W6DFDXye_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HJN5zvKl, 1, m, &cVar_HJN5zvKl_sendMessage);
}

void Heavy_wstd_eq::cBinop_5CalOhTS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ja4AnvAn, HV_BINOP_MULTIPLY, 1, m, &cBinop_ja4AnvAn_sendMessage);
}

void Heavy_wstd_eq::cMsg_pMz9Gi9s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_JcgPbhls_sendMessage);
}

void Heavy_wstd_eq::cBinop_JcgPbhls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NPPJsUWL, HV_BINOP_MULTIPLY, 1, m, &cBinop_NPPJsUWL_sendMessage);
}

void Heavy_wstd_eq::cVar_HJN5zvKl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6y5UdcZk_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cVar_6cafKgtk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7TMcazUZ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_U7lUAwkq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5U6TI2sH_sendMessage);
}

void Heavy_wstd_eq::cVar_BoQ186Ki_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_g2xsoBKq_sendMessage);
}

void Heavy_wstd_eq::cCast_CmBOjU5w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_sxYTqrCO_sendMessage);
}

void Heavy_wstd_eq::cCast_u4semES9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_di6A288r_sendMessage);
}

void Heavy_wstd_eq::cSend_dZiECMYY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_v0Lmm0An_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_daRCber9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_hYrx8yU2_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_aoJqicXQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8WiVvIXd_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_Wvf2SGG5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_8HAmf41j_sendMessage);
}

void Heavy_wstd_eq::cBinop_8HAmf41j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GL1LG7TI, HV_BINOP_MULTIPLY, 1, m, &cBinop_GL1LG7TI_sendMessage);
}

void Heavy_wstd_eq::cBinop_GL1LG7TI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_38NbfpOn_sendMessage);
}

void Heavy_wstd_eq::cBinop_38NbfpOn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_aoJqicXQ_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_6y5UdcZk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_IzYJEPOd_sendMessage);
}

void Heavy_wstd_eq::cBinop_IzYJEPOd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8oVzMOm1_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sFX0VD42_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_m7uVpKLA_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lNdiLjRN_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1sJYMPTB_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wyh9WWSV_sendMessage);
}

void Heavy_wstd_eq::cBinop_J06v5yYD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QpEX9eje_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_rewiAiEL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_E1opgaqd_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_GSacWdsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jJ2rkFlF_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_ja4AnvAn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_y1Bnrgbc_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_NPPJsUWL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9utkxPsn_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cCast_RfTlUGfN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6cafKgtk, 0, m, &cVar_6cafKgtk_sendMessage);
}

void Heavy_wstd_eq::cCast_NNf05q11_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BoQ186Ki, 1, m, &cVar_BoQ186Ki_sendMessage);
}

void Heavy_wstd_eq::cCast_lNdiLjRN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GSacWdsX, HV_BINOP_MULTIPLY, 0, m, &cBinop_GSacWdsX_sendMessage);
}

void Heavy_wstd_eq::cCast_sFX0VD42_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NPPJsUWL, HV_BINOP_MULTIPLY, 0, m, &cBinop_NPPJsUWL_sendMessage);
}

void Heavy_wstd_eq::cCast_8oVzMOm1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_wstd_eq::cCast_m7uVpKLA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ja4AnvAn, HV_BINOP_MULTIPLY, 0, m, &cBinop_ja4AnvAn_sendMessage);
}

void Heavy_wstd_eq::cCast_1sJYMPTB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rewiAiEL, HV_BINOP_MULTIPLY, 0, m, &cBinop_rewiAiEL_sendMessage);
}

void Heavy_wstd_eq::cCast_wyh9WWSV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J06v5yYD, HV_BINOP_MULTIPLY, 0, m, &cBinop_J06v5yYD_sendMessage);
}

void Heavy_wstd_eq::cCast_7TMcazUZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BoQ186Ki, 0, m, &cVar_BoQ186Ki_sendMessage);
}

void Heavy_wstd_eq::cCast_5U6TI2sH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HJN5zvKl, 0, m, &cVar_HJN5zvKl_sendMessage);
}

void Heavy_wstd_eq::cMsg_0n5WxuAV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_nLfKhxvm, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_bmd1myHC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_zzqm33Vi, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_rgViEhpu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_jeFy1iqT, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_FPVS7kwr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_IIerTTpM, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_Ks15yGF0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_e1eH3MOt, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_Dm6b7ImK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_m8nxixFJ_sendMessage);
}

void Heavy_wstd_eq::cSystem_m8nxixFJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gBKLUD3o, HV_BINOP_DIVIDE, 1, m, &cBinop_gBKLUD3o_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_l78ZgTgY_sendMessage);
}

void Heavy_wstd_eq::cUnop_qzsnPIHc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_aub0eD2P_sendMessage);
}

void Heavy_wstd_eq::cMsg_fazTDjYw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_qzsnPIHc_sendMessage);
}

void Heavy_wstd_eq::cBinop_aub0eD2P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gBKLUD3o, HV_BINOP_DIVIDE, 0, m, &cBinop_gBKLUD3o_sendMessage);
}

void Heavy_wstd_eq::cCast_l78ZgTgY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fazTDjYw_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_gBKLUD3o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vxhcQGiU, HV_BINOP_MULTIPLY, 1, m, &cBinop_vxhcQGiU_sendMessage);
}

void Heavy_wstd_eq::cBinop_vxhcQGiU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4igJB6B9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lc4mf6vK_sendMessage);
}

void Heavy_wstd_eq::cUnop_1Rbsmk3x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_kHbg7tkJ_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cUnop_9rGZSI9t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_SEnduVt0_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_kuODZmz5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_3fHEtbxj_sendMessage);
}

void Heavy_wstd_eq::cBinop_3fHEtbxj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vxhcQGiU, HV_BINOP_MULTIPLY, 0, m, &cBinop_vxhcQGiU_sendMessage);
}

void Heavy_wstd_eq::cBinop_5JSzrBwp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_4n47yel1_sendMessage);
}

void Heavy_wstd_eq::cBinop_4n47yel1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Fo7XhUee_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_FLd9FElP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nizlHlKk, 1, m, &cVar_nizlHlKk_sendMessage);
}

void Heavy_wstd_eq::cVar_nizlHlKk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uBczg8HP_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_Wm4JevUv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GcZxm1Cb, HV_BINOP_MULTIPLY, 1, m, &cBinop_GcZxm1Cb_sendMessage);
}

void Heavy_wstd_eq::cBinop_dTQA2YUT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_Wm4JevUv_sendMessage);
}

void Heavy_wstd_eq::cBinop_K9nB2L42_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_j2o7UsEE_sendMessage);
}

void Heavy_wstd_eq::cBinop_j2o7UsEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0eShUvDe, HV_BINOP_MULTIPLY, 1, m, &cBinop_0eShUvDe_sendMessage);
}

void Heavy_wstd_eq::cBinop_l1fA05b0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UNZmVdTO, HV_BINOP_MULTIPLY, 1, m, &cBinop_UNZmVdTO_sendMessage);
}

void Heavy_wstd_eq::cBinop_TNkl6rKw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_l1fA05b0_sendMessage);
}

void Heavy_wstd_eq::cBinop_g4ZurPCj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UO6brczF, HV_BINOP_MULTIPLY, 1, m, &cBinop_UO6brczF_sendMessage);
}

void Heavy_wstd_eq::cMsg_BK4HB5iy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_gxwz5ags_sendMessage);
}

void Heavy_wstd_eq::cBinop_gxwz5ags_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IiaksrBh, HV_BINOP_MULTIPLY, 1, m, &cBinop_IiaksrBh_sendMessage);
}

void Heavy_wstd_eq::cVar_AKSUevQt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZdpVs6ty_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_kuODZmz5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_P9nzRVbw_sendMessage);
}

void Heavy_wstd_eq::cVar_imyXB36a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_5JSzrBwp_sendMessage);
}

void Heavy_wstd_eq::cCast_lc4mf6vK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_9rGZSI9t_sendMessage);
}

void Heavy_wstd_eq::cCast_4igJB6B9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_1Rbsmk3x_sendMessage);
}

void Heavy_wstd_eq::cSend_kHbg7tkJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ArHUBWem_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_SEnduVt0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WAD84sPX_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_r2JXti0Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_95yoQY2G_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_Fo7XhUee_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_RE2GLn7L_sendMessage);
}

void Heavy_wstd_eq::cBinop_RE2GLn7L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tkFA5dwr, HV_BINOP_MULTIPLY, 1, m, &cBinop_tkFA5dwr_sendMessage);
}

void Heavy_wstd_eq::cBinop_tkFA5dwr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_4q5wMHMV_sendMessage);
}

void Heavy_wstd_eq::cBinop_4q5wMHMV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_r2JXti0Q_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_uBczg8HP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_8IusfvG9_sendMessage);
}

void Heavy_wstd_eq::cBinop_8IusfvG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_x0092iZi_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XSDJVpUb_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7TRbqQ8U_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AmoJaoT8_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Y3L5MWaX_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Z00hbvoq_sendMessage);
}

void Heavy_wstd_eq::cBinop_GcZxm1Cb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0n5WxuAV_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_0eShUvDe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bmd1myHC_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_UNZmVdTO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rgViEhpu_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_UO6brczF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FPVS7kwr_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_IiaksrBh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ks15yGF0_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cCast_SxYKnUqI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AKSUevQt, 0, m, &cVar_AKSUevQt_sendMessage);
}

void Heavy_wstd_eq::cCast_qksw8WmE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_imyXB36a, 1, m, &cVar_imyXB36a_sendMessage);
}

void Heavy_wstd_eq::cCast_Y3L5MWaX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0eShUvDe, HV_BINOP_MULTIPLY, 0, m, &cBinop_0eShUvDe_sendMessage);
}

void Heavy_wstd_eq::cCast_AmoJaoT8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UNZmVdTO, HV_BINOP_MULTIPLY, 0, m, &cBinop_UNZmVdTO_sendMessage);
}

void Heavy_wstd_eq::cCast_XSDJVpUb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IiaksrBh, HV_BINOP_MULTIPLY, 0, m, &cBinop_IiaksrBh_sendMessage);
}

void Heavy_wstd_eq::cCast_x0092iZi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_wstd_eq::cCast_7TRbqQ8U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UO6brczF, HV_BINOP_MULTIPLY, 0, m, &cBinop_UO6brczF_sendMessage);
}

void Heavy_wstd_eq::cCast_Z00hbvoq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GcZxm1Cb, HV_BINOP_MULTIPLY, 0, m, &cBinop_GcZxm1Cb_sendMessage);
}

void Heavy_wstd_eq::cCast_ZdpVs6ty_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_imyXB36a, 0, m, &cVar_imyXB36a_sendMessage);
}

void Heavy_wstd_eq::cCast_P9nzRVbw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nizlHlKk, 0, m, &cVar_nizlHlKk_sendMessage);
}

void Heavy_wstd_eq::cIf_DlScNNaG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_Y3Q4QJER, m);
      break;
    }
    default: return;
  }
}

void Heavy_wstd_eq::cIf_LiRg470r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_2fLB5Mbi, HV_BINOP_MULTIPLY, 0, m, &cBinop_2fLB5Mbi_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_2fLB5Mbi, HV_BINOP_MULTIPLY, 1, m, &cBinop_2fLB5Mbi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_wstd_eq::cIf_C0SX6XPG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_siORK6KE, m);
      break;
    }
    default: return;
  }
}

void Heavy_wstd_eq::cIf_d6TBOl54_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_KZOhDse2, HV_BINOP_MULTIPLY, 0, m, &cBinop_KZOhDse2_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_KZOhDse2, HV_BINOP_MULTIPLY, 1, m, &cBinop_KZOhDse2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_wstd_eq::cIf_TMFdKxlq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.08f, 0, m, &cBinop_NUca74jE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_wstd_eq::cIf_azvUkfT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_dBQfmjlY, HV_BINOP_MULTIPLY, 0, m, &cBinop_dBQfmjlY_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_dBQfmjlY, HV_BINOP_MULTIPLY, 1, m, &cBinop_dBQfmjlY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_wstd_eq::cMsg_Gg7u5Lub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_URNX4PJ3_sendMessage);
}

void Heavy_wstd_eq::cSystem_URNX4PJ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_tmjyPa6V_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_QTFeeasK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_3AuKKgR1, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_sJEMX36S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_bcwFn5rP, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_0M30q7D2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_f32Mh9jI, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_B5P2D2MX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_bG3mC0oE, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_ixspVlDm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_VaVXtgnd, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_RZSFRXWn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sanCHyrl_sendMessage);
}

void Heavy_wstd_eq::cSystem_sanCHyrl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ewq79oGj, HV_BINOP_DIVIDE, 1, m, &cBinop_ewq79oGj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NGRKcmVY_sendMessage);
}

void Heavy_wstd_eq::cUnop_2dZTYjK0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_b6i0KbaO_sendMessage);
}

void Heavy_wstd_eq::cMsg_52IfPwJA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_2dZTYjK0_sendMessage);
}

void Heavy_wstd_eq::cBinop_b6i0KbaO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ewq79oGj, HV_BINOP_DIVIDE, 0, m, &cBinop_ewq79oGj_sendMessage);
}

void Heavy_wstd_eq::cCast_NGRKcmVY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_52IfPwJA_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_ewq79oGj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2nuDAqzZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_2nuDAqzZ_sendMessage);
}

void Heavy_wstd_eq::cBinop_2nuDAqzZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4gjlF0y6_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hB0GaIqi_sendMessage);
}

void Heavy_wstd_eq::cUnop_5GvHKlkr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_6YUMdgyL_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cUnop_AtLAwAke_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lT1DsVGW_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_LsBz8KXk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_IBF2roR1_sendMessage);
}

void Heavy_wstd_eq::cBinop_IBF2roR1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2nuDAqzZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_2nuDAqzZ_sendMessage);
}

void Heavy_wstd_eq::cBinop_DGJ4IzPy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_kfbqxONp_sendMessage);
}

void Heavy_wstd_eq::cBinop_kfbqxONp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7dRLWA8s_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_LAx7tpzV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EHUsOm4q, 1, m, &cVar_EHUsOm4q_sendMessage);
}

void Heavy_wstd_eq::cVar_EHUsOm4q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Lgt8anlx_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_3pw7bWCm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_DvjGynUj_sendMessage);
}

void Heavy_wstd_eq::cBinop_DvjGynUj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qPud3rYV, HV_BINOP_MULTIPLY, 1, m, &cBinop_qPud3rYV_sendMessage);
}

void Heavy_wstd_eq::cBinop_cex0ZnPy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zcFL05fS, HV_BINOP_MULTIPLY, 1, m, &cBinop_zcFL05fS_sendMessage);
}

void Heavy_wstd_eq::cBinop_Ka2KeOy7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ghcUsuuj, HV_BINOP_MULTIPLY, 1, m, &cBinop_ghcUsuuj_sendMessage);
}

void Heavy_wstd_eq::cBinop_YRBkuIKT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QglZuqQf, HV_BINOP_MULTIPLY, 1, m, &cBinop_QglZuqQf_sendMessage);
}

void Heavy_wstd_eq::cMsg_vgdywLKA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_jMxU1ndj_sendMessage);
}

void Heavy_wstd_eq::cBinop_jMxU1ndj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wWrn26Os, HV_BINOP_MULTIPLY, 1, m, &cBinop_wWrn26Os_sendMessage);
}

void Heavy_wstd_eq::cVar_FvYqaoDT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Dm7WuHBm_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_LsBz8KXk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4V4TVUIm_sendMessage);
}

void Heavy_wstd_eq::cVar_YuKdDjg8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_DGJ4IzPy_sendMessage);
}

void Heavy_wstd_eq::cCast_hB0GaIqi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_AtLAwAke_sendMessage);
}

void Heavy_wstd_eq::cCast_4gjlF0y6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_5GvHKlkr_sendMessage);
}

void Heavy_wstd_eq::cSend_6YUMdgyL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_JRP6DdMm_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_lT1DsVGW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Rqlf3Jtm_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_0XgwkssA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_16ZPDNVW_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_7dRLWA8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_SkldzFbK_sendMessage);
}

void Heavy_wstd_eq::cBinop_SkldzFbK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OfJnEpyj, HV_BINOP_MULTIPLY, 1, m, &cBinop_OfJnEpyj_sendMessage);
}

void Heavy_wstd_eq::cBinop_OfJnEpyj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_iJOlFeGT_sendMessage);
}

void Heavy_wstd_eq::cBinop_iJOlFeGT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_0XgwkssA_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_Lgt8anlx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_U4tZmWMp_sendMessage);
}

void Heavy_wstd_eq::cBinop_U4tZmWMp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KljVgp7y_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KMaDQptD_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wrGyEq6l_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OKryPOAM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6XQRpOwH_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fbbwdLr5_sendMessage);
}

void Heavy_wstd_eq::cBinop_qPud3rYV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QTFeeasK_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_zcFL05fS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sJEMX36S_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_ghcUsuuj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0M30q7D2_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_QglZuqQf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_B5P2D2MX_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_wWrn26Os_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ixspVlDm_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cCast_np3jTndP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YuKdDjg8, 1, m, &cVar_YuKdDjg8_sendMessage);
}

void Heavy_wstd_eq::cCast_nVT701hZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FvYqaoDT, 0, m, &cVar_FvYqaoDT_sendMessage);
}

void Heavy_wstd_eq::cCast_fbbwdLr5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qPud3rYV, HV_BINOP_MULTIPLY, 0, m, &cBinop_qPud3rYV_sendMessage);
}

void Heavy_wstd_eq::cCast_wrGyEq6l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QglZuqQf, HV_BINOP_MULTIPLY, 0, m, &cBinop_QglZuqQf_sendMessage);
}

void Heavy_wstd_eq::cCast_KMaDQptD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wWrn26Os, HV_BINOP_MULTIPLY, 0, m, &cBinop_wWrn26Os_sendMessage);
}

void Heavy_wstd_eq::cCast_6XQRpOwH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zcFL05fS, HV_BINOP_MULTIPLY, 0, m, &cBinop_zcFL05fS_sendMessage);
}

void Heavy_wstd_eq::cCast_OKryPOAM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ghcUsuuj, HV_BINOP_MULTIPLY, 0, m, &cBinop_ghcUsuuj_sendMessage);
}

void Heavy_wstd_eq::cCast_KljVgp7y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_wstd_eq::cCast_4V4TVUIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EHUsOm4q, 0, m, &cVar_EHUsOm4q_sendMessage);
}

void Heavy_wstd_eq::cCast_Dm7WuHBm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YuKdDjg8, 0, m, &cVar_YuKdDjg8_sendMessage);
}

void Heavy_wstd_eq::cMsg_7LIQC6qZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_vq700BJN, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_8CqXr3IP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_i9GvfDsr, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_deazWprx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_I1vncudL, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_Ty9BOSEi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_rno2IaiJ, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_Q4amNom4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_HgwSifwP, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_txb7BUsU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mN9C7wnW_sendMessage);
}

void Heavy_wstd_eq::cSystem_mN9C7wnW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4xDH3BEa, HV_BINOP_DIVIDE, 1, m, &cBinop_4xDH3BEa_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bHHuNESv_sendMessage);
}

void Heavy_wstd_eq::cUnop_8F6GnRuZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_SozenKJY_sendMessage);
}

void Heavy_wstd_eq::cMsg_x4L0Fq4M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_8F6GnRuZ_sendMessage);
}

void Heavy_wstd_eq::cBinop_SozenKJY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4xDH3BEa, HV_BINOP_DIVIDE, 0, m, &cBinop_4xDH3BEa_sendMessage);
}

void Heavy_wstd_eq::cCast_bHHuNESv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_x4L0Fq4M_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_4xDH3BEa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ts7vVgIs, HV_BINOP_MULTIPLY, 1, m, &cBinop_Ts7vVgIs_sendMessage);
}

void Heavy_wstd_eq::cBinop_Ts7vVgIs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bbgJzvGt_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_V1uf9xRv_sendMessage);
}

void Heavy_wstd_eq::cUnop_Q1VmkjO6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_aS2eIcsI_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cUnop_jftrZZ1g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_sKHwwBNz_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_cVrv5XnS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_HgqqN4Lu_sendMessage);
}

void Heavy_wstd_eq::cBinop_HgqqN4Lu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ts7vVgIs, HV_BINOP_MULTIPLY, 0, m, &cBinop_Ts7vVgIs_sendMessage);
}

void Heavy_wstd_eq::cBinop_t9HqS10s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_GaCWiETX_sendMessage);
}

void Heavy_wstd_eq::cBinop_GaCWiETX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nJpoPRYK_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_epzatWDB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FrWyiep6, 1, m, &cVar_FrWyiep6_sendMessage);
}

void Heavy_wstd_eq::cVar_FrWyiep6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_H0aJsShB_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_smf8gIo3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_c1kuN3db_sendMessage);
}

void Heavy_wstd_eq::cBinop_c1kuN3db_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z0kWJY3U, HV_BINOP_MULTIPLY, 1, m, &cBinop_Z0kWJY3U_sendMessage);
}

void Heavy_wstd_eq::cBinop_k8kINi8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_riiRQed9, HV_BINOP_MULTIPLY, 1, m, &cBinop_riiRQed9_sendMessage);
}

void Heavy_wstd_eq::cBinop_8veZDglL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_068CmPwx, HV_BINOP_MULTIPLY, 1, m, &cBinop_068CmPwx_sendMessage);
}

void Heavy_wstd_eq::cBinop_pe4dNYW6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_khFdmSnD, HV_BINOP_MULTIPLY, 1, m, &cBinop_khFdmSnD_sendMessage);
}

void Heavy_wstd_eq::cMsg_LE3U1ghe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_IKAdLqnq_sendMessage);
}

void Heavy_wstd_eq::cBinop_IKAdLqnq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QbMX68LS, HV_BINOP_MULTIPLY, 1, m, &cBinop_QbMX68LS_sendMessage);
}

void Heavy_wstd_eq::cVar_fgj51JW5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3TrGyQlI_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_cVrv5XnS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wqwuPEYK_sendMessage);
}

void Heavy_wstd_eq::cVar_OwncpxSE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_t9HqS10s_sendMessage);
}

void Heavy_wstd_eq::cCast_V1uf9xRv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_jftrZZ1g_sendMessage);
}

void Heavy_wstd_eq::cCast_bbgJzvGt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_Q1VmkjO6_sendMessage);
}

void Heavy_wstd_eq::cSend_aS2eIcsI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Re5Pa0dr_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_sKHwwBNz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_JMsEdRae_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_aGQ5j4Ve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_JcgcQDY4_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_nJpoPRYK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_u7xypHr3_sendMessage);
}

void Heavy_wstd_eq::cBinop_u7xypHr3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CuDWHqcF, HV_BINOP_MULTIPLY, 1, m, &cBinop_CuDWHqcF_sendMessage);
}

void Heavy_wstd_eq::cBinop_CuDWHqcF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_3nGT85LG_sendMessage);
}

void Heavy_wstd_eq::cBinop_3nGT85LG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_aGQ5j4Ve_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_H0aJsShB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_SUZiWxPL_sendMessage);
}

void Heavy_wstd_eq::cBinop_SUZiWxPL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ykilQBjr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PFUYEa8a_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YHEK7qfM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nPHliaSe_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6GaThuVJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VAXG5xmT_sendMessage);
}

void Heavy_wstd_eq::cBinop_Z0kWJY3U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7LIQC6qZ_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_riiRQed9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8CqXr3IP_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_068CmPwx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_deazWprx_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_khFdmSnD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ty9BOSEi_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_QbMX68LS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Q4amNom4_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cCast_n07s2PAs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OwncpxSE, 1, m, &cVar_OwncpxSE_sendMessage);
}

void Heavy_wstd_eq::cCast_pxwulUz4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fgj51JW5, 0, m, &cVar_fgj51JW5_sendMessage);
}

void Heavy_wstd_eq::cCast_ykilQBjr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_wstd_eq::cCast_nPHliaSe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_068CmPwx, HV_BINOP_MULTIPLY, 0, m, &cBinop_068CmPwx_sendMessage);
}

void Heavy_wstd_eq::cCast_YHEK7qfM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_khFdmSnD, HV_BINOP_MULTIPLY, 0, m, &cBinop_khFdmSnD_sendMessage);
}

void Heavy_wstd_eq::cCast_PFUYEa8a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QbMX68LS, HV_BINOP_MULTIPLY, 0, m, &cBinop_QbMX68LS_sendMessage);
}

void Heavy_wstd_eq::cCast_6GaThuVJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_riiRQed9, HV_BINOP_MULTIPLY, 0, m, &cBinop_riiRQed9_sendMessage);
}

void Heavy_wstd_eq::cCast_VAXG5xmT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z0kWJY3U, HV_BINOP_MULTIPLY, 0, m, &cBinop_Z0kWJY3U_sendMessage);
}

void Heavy_wstd_eq::cCast_3TrGyQlI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OwncpxSE, 0, m, &cVar_OwncpxSE_sendMessage);
}

void Heavy_wstd_eq::cCast_wqwuPEYK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FrWyiep6, 0, m, &cVar_FrWyiep6_sendMessage);
}

void Heavy_wstd_eq::cMsg_9Tz9b5ee_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_8tMwStS8, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_UTJDhQAJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_8yBMw5rJ, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_0kko9GMj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_RIWIBagb, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_UqJD7cxN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_w7wZGwm5, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_QGqTsrEg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_uCx77GAz, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_qvSfaioT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_s5ROqiE7_sendMessage);
}

void Heavy_wstd_eq::cSystem_s5ROqiE7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tfo72dou, HV_BINOP_DIVIDE, 1, m, &cBinop_tfo72dou_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MMEZsy0y_sendMessage);
}

void Heavy_wstd_eq::cUnop_dK1rewFV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_uevYc2gS_sendMessage);
}

void Heavy_wstd_eq::cMsg_DSxinza7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_dK1rewFV_sendMessage);
}

void Heavy_wstd_eq::cBinop_uevYc2gS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tfo72dou, HV_BINOP_DIVIDE, 0, m, &cBinop_tfo72dou_sendMessage);
}

void Heavy_wstd_eq::cCast_MMEZsy0y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DSxinza7_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_tfo72dou_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ro1EeLsJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_Ro1EeLsJ_sendMessage);
}

void Heavy_wstd_eq::cBinop_Ro1EeLsJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aaWHkMVl_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SQZH1uC9_sendMessage);
}

void Heavy_wstd_eq::cUnop_nk3EmBkU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_2gv2Ahy7_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cUnop_QXokLbz7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Sp6uhCri_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_qSC1eLyQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_fbnrDZd5_sendMessage);
}

void Heavy_wstd_eq::cBinop_fbnrDZd5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ro1EeLsJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_Ro1EeLsJ_sendMessage);
}

void Heavy_wstd_eq::cBinop_8CzmwBJk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_oihm37Cs_sendMessage);
}

void Heavy_wstd_eq::cBinop_oihm37Cs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mAglN41M_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_ruNUAnj7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3bOxKv4u, 1, m, &cVar_3bOxKv4u_sendMessage);
}

void Heavy_wstd_eq::cVar_3bOxKv4u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9C3c2c95_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_NdMO1I46_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hYZ0yeBx, HV_BINOP_MULTIPLY, 1, m, &cBinop_hYZ0yeBx_sendMessage);
}

void Heavy_wstd_eq::cBinop_JFR1t0Dj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_NdMO1I46_sendMessage);
}

void Heavy_wstd_eq::cBinop_dSAVtgeP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_nqtmqPEy_sendMessage);
}

void Heavy_wstd_eq::cBinop_nqtmqPEy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zqnKiLkx, HV_BINOP_MULTIPLY, 1, m, &cBinop_zqnKiLkx_sendMessage);
}

void Heavy_wstd_eq::cBinop_rQTxWBV1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_57zeqwDX, HV_BINOP_MULTIPLY, 1, m, &cBinop_57zeqwDX_sendMessage);
}

void Heavy_wstd_eq::cBinop_u5iBDUfh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_rQTxWBV1_sendMessage);
}

void Heavy_wstd_eq::cBinop_KuXHerUd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ouGkGY8o, HV_BINOP_MULTIPLY, 1, m, &cBinop_ouGkGY8o_sendMessage);
}

void Heavy_wstd_eq::cMsg_n1QyUYnr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_3LoItHY7_sendMessage);
}

void Heavy_wstd_eq::cBinop_3LoItHY7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BrZmkZWd, HV_BINOP_MULTIPLY, 1, m, &cBinop_BrZmkZWd_sendMessage);
}

void Heavy_wstd_eq::cVar_vXGUJsA2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FRrx29CI_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_qSC1eLyQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_O3NoomzH_sendMessage);
}

void Heavy_wstd_eq::cVar_GiCEwxVr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_8CzmwBJk_sendMessage);
}

void Heavy_wstd_eq::cCast_SQZH1uC9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_QXokLbz7_sendMessage);
}

void Heavy_wstd_eq::cCast_aaWHkMVl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_nk3EmBkU_sendMessage);
}

void Heavy_wstd_eq::cSend_2gv2Ahy7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_IqkvICmX_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_Sp6uhCri_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_beA3dDhm_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_eHZFXQ4H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_OVFX62Nq_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_mAglN41M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_IueIeAsq_sendMessage);
}

void Heavy_wstd_eq::cBinop_IueIeAsq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8eaZgnn4, HV_BINOP_MULTIPLY, 1, m, &cBinop_8eaZgnn4_sendMessage);
}

void Heavy_wstd_eq::cBinop_8eaZgnn4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_NPXhJKRK_sendMessage);
}

void Heavy_wstd_eq::cBinop_NPXhJKRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_eHZFXQ4H_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_9C3c2c95_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_YkTwW3ye_sendMessage);
}

void Heavy_wstd_eq::cBinop_YkTwW3ye_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_g7jzNoCV_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_k6cP4cX9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GLAR8vw6_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cQAeNGxC_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CIrhxOcv_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VuqnJ7dO_sendMessage);
}

void Heavy_wstd_eq::cBinop_hYZ0yeBx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9Tz9b5ee_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_zqnKiLkx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UTJDhQAJ_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_57zeqwDX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0kko9GMj_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_ouGkGY8o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UqJD7cxN_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_BrZmkZWd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QGqTsrEg_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cCast_FcWpUFnM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vXGUJsA2, 0, m, &cVar_vXGUJsA2_sendMessage);
}

void Heavy_wstd_eq::cCast_Q8n9DUug_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GiCEwxVr, 1, m, &cVar_GiCEwxVr_sendMessage);
}

void Heavy_wstd_eq::cCast_g7jzNoCV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_wstd_eq::cCast_CIrhxOcv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zqnKiLkx, HV_BINOP_MULTIPLY, 0, m, &cBinop_zqnKiLkx_sendMessage);
}

void Heavy_wstd_eq::cCast_VuqnJ7dO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hYZ0yeBx, HV_BINOP_MULTIPLY, 0, m, &cBinop_hYZ0yeBx_sendMessage);
}

void Heavy_wstd_eq::cCast_cQAeNGxC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_57zeqwDX, HV_BINOP_MULTIPLY, 0, m, &cBinop_57zeqwDX_sendMessage);
}

void Heavy_wstd_eq::cCast_GLAR8vw6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ouGkGY8o, HV_BINOP_MULTIPLY, 0, m, &cBinop_ouGkGY8o_sendMessage);
}

void Heavy_wstd_eq::cCast_k6cP4cX9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BrZmkZWd, HV_BINOP_MULTIPLY, 0, m, &cBinop_BrZmkZWd_sendMessage);
}

void Heavy_wstd_eq::cCast_FRrx29CI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GiCEwxVr, 0, m, &cVar_GiCEwxVr_sendMessage);
}

void Heavy_wstd_eq::cCast_O3NoomzH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3bOxKv4u, 0, m, &cVar_3bOxKv4u_sendMessage);
}

void Heavy_wstd_eq::cMsg_1E8yu61B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_VPXdhIMd, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_M1lYyuBo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_mNjNpQGS, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_f5Rl3J0M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_WcJcmCe9, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_643cIPnR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_spjpFrne, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_wZxTofrg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ObqsHhQG, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_bKFO3Kq5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NppW2IV8_sendMessage);
}

void Heavy_wstd_eq::cSystem_NppW2IV8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sWsdXZkt, HV_BINOP_DIVIDE, 1, m, &cBinop_sWsdXZkt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8ULf8ah4_sendMessage);
}

void Heavy_wstd_eq::cUnop_4H3ECCku_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_K4LOWvUS_sendMessage);
}

void Heavy_wstd_eq::cMsg_2adcBC1S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_4H3ECCku_sendMessage);
}

void Heavy_wstd_eq::cBinop_K4LOWvUS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sWsdXZkt, HV_BINOP_DIVIDE, 0, m, &cBinop_sWsdXZkt_sendMessage);
}

void Heavy_wstd_eq::cCast_8ULf8ah4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2adcBC1S_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_sWsdXZkt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HCfgy3hm, HV_BINOP_MULTIPLY, 1, m, &cBinop_HCfgy3hm_sendMessage);
}

void Heavy_wstd_eq::cBinop_HCfgy3hm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WHN8G0Bu_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1ilGsenD_sendMessage);
}

void Heavy_wstd_eq::cUnop_eshsT9Q4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_gBqEbUdT_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cUnop_siMJeVwU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_8EqZ09dP_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_R3meU2oJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_QqkI81HG_sendMessage);
}

void Heavy_wstd_eq::cBinop_QqkI81HG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HCfgy3hm, HV_BINOP_MULTIPLY, 0, m, &cBinop_HCfgy3hm_sendMessage);
}

void Heavy_wstd_eq::cBinop_cD3hpBAu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_Z6vjHuiq_sendMessage);
}

void Heavy_wstd_eq::cBinop_Z6vjHuiq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jydikRkq_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_cw5hSKTg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vkJrAjv7, HV_BINOP_MULTIPLY, 1, m, &cBinop_vkJrAjv7_sendMessage);
}

void Heavy_wstd_eq::cMsg_Wjfazvpf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_0TnWxlWy_sendMessage);
}

void Heavy_wstd_eq::cBinop_0TnWxlWy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_cw5hSKTg_sendMessage);
}

void Heavy_wstd_eq::cMsg_yhDCCyiS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_Dw5oewMV_sendMessage);
}

void Heavy_wstd_eq::cBinop_Dw5oewMV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NTVGldgC, HV_BINOP_MULTIPLY, 1, m, &cBinop_NTVGldgC_sendMessage);
}

void Heavy_wstd_eq::cBinop_jQSxBcRE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9ICPEsDb, HV_BINOP_MULTIPLY, 1, m, &cBinop_9ICPEsDb_sendMessage);
}

void Heavy_wstd_eq::cMsg_XI9iVA6x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_DNftgGqS_sendMessage);
}

void Heavy_wstd_eq::cBinop_DNftgGqS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_jQSxBcRE_sendMessage);
}

void Heavy_wstd_eq::cBinop_8rsm7o9e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JnHNR5An, 1, m, &cVar_JnHNR5An_sendMessage);
}

void Heavy_wstd_eq::cBinop_Vt6hkxMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bFITaL6g, HV_BINOP_MULTIPLY, 1, m, &cBinop_bFITaL6g_sendMessage);
}

void Heavy_wstd_eq::cMsg_AJ5v4o4g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_ShOmNW8u_sendMessage);
}

void Heavy_wstd_eq::cBinop_ShOmNW8u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_clRIYe7R, HV_BINOP_MULTIPLY, 1, m, &cBinop_clRIYe7R_sendMessage);
}

void Heavy_wstd_eq::cVar_JnHNR5An_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_R06hgvxa_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cVar_Od4mGS29_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eyMhI1SQ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_R3meU2oJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_v2x2a6a1_sendMessage);
}

void Heavy_wstd_eq::cVar_ScleBLJ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_cD3hpBAu_sendMessage);
}

void Heavy_wstd_eq::cCast_WHN8G0Bu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_eshsT9Q4_sendMessage);
}

void Heavy_wstd_eq::cCast_1ilGsenD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_siMJeVwU_sendMessage);
}

void Heavy_wstd_eq::cSend_gBqEbUdT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Ooo2CFxB_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_8EqZ09dP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_D1klMwit_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_L1g6J1Yd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_bbigd7Ie_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_jydikRkq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_5Zk4Ftli_sendMessage);
}

void Heavy_wstd_eq::cBinop_5Zk4Ftli_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SY7kozBK, HV_BINOP_MULTIPLY, 1, m, &cBinop_SY7kozBK_sendMessage);
}

void Heavy_wstd_eq::cBinop_SY7kozBK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_qO0qOREd_sendMessage);
}

void Heavy_wstd_eq::cBinop_qO0qOREd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_L1g6J1Yd_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_R06hgvxa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_HPtmMoY5_sendMessage);
}

void Heavy_wstd_eq::cBinop_HPtmMoY5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SEmKYDo7_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_33kPwJzF_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_swrn1mrF_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EtPWsnS3_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_i1GYrj2P_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GN4V0DUu_sendMessage);
}

void Heavy_wstd_eq::cBinop_vkJrAjv7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1E8yu61B_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_NTVGldgC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_M1lYyuBo_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_9ICPEsDb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_f5Rl3J0M_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_bFITaL6g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_643cIPnR_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_clRIYe7R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wZxTofrg_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cCast_q9XgeUuV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ScleBLJ8, 1, m, &cVar_ScleBLJ8_sendMessage);
}

void Heavy_wstd_eq::cCast_Vk9okeEh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Od4mGS29, 0, m, &cVar_Od4mGS29_sendMessage);
}

void Heavy_wstd_eq::cCast_SEmKYDo7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_wstd_eq::cCast_swrn1mrF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bFITaL6g, HV_BINOP_MULTIPLY, 0, m, &cBinop_bFITaL6g_sendMessage);
}

void Heavy_wstd_eq::cCast_33kPwJzF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_clRIYe7R, HV_BINOP_MULTIPLY, 0, m, &cBinop_clRIYe7R_sendMessage);
}

void Heavy_wstd_eq::cCast_i1GYrj2P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NTVGldgC, HV_BINOP_MULTIPLY, 0, m, &cBinop_NTVGldgC_sendMessage);
}

void Heavy_wstd_eq::cCast_GN4V0DUu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vkJrAjv7, HV_BINOP_MULTIPLY, 0, m, &cBinop_vkJrAjv7_sendMessage);
}

void Heavy_wstd_eq::cCast_EtPWsnS3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9ICPEsDb, HV_BINOP_MULTIPLY, 0, m, &cBinop_9ICPEsDb_sendMessage);
}

void Heavy_wstd_eq::cCast_eyMhI1SQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ScleBLJ8, 0, m, &cVar_ScleBLJ8_sendMessage);
}

void Heavy_wstd_eq::cCast_v2x2a6a1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JnHNR5An, 0, m, &cVar_JnHNR5An_sendMessage);
}

void Heavy_wstd_eq::cMsg_k5nkdKU9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_EHa9ktCW, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_4Y1KnuqN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_U9fDmIJ3, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_tkquMJPk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Ue3T7NXd, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_HNnKJ84o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ruVvxswo, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_bNJzsJqY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_l3fYti6K, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_XE1ToMtB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iJFnHPLU_sendMessage);
}

void Heavy_wstd_eq::cSystem_iJFnHPLU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YiDmkWhh, HV_BINOP_DIVIDE, 1, m, &cBinop_YiDmkWhh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Baq3RikW_sendMessage);
}

void Heavy_wstd_eq::cUnop_831C17yB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_rxGoFlmB_sendMessage);
}

void Heavy_wstd_eq::cMsg_WKC971nW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_831C17yB_sendMessage);
}

void Heavy_wstd_eq::cBinop_rxGoFlmB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YiDmkWhh, HV_BINOP_DIVIDE, 0, m, &cBinop_YiDmkWhh_sendMessage);
}

void Heavy_wstd_eq::cCast_Baq3RikW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WKC971nW_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_YiDmkWhh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WYGuv6iW, HV_BINOP_MULTIPLY, 1, m, &cBinop_WYGuv6iW_sendMessage);
}

void Heavy_wstd_eq::cBinop_WYGuv6iW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_erLvrMrw_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dgB9rayk_sendMessage);
}

void Heavy_wstd_eq::cUnop_Jue56Jwn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_5hzq7DgX_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cUnop_S5zge05a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_OrEPuIp9_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_srbUcmkD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_INwO6uqs_sendMessage);
}

void Heavy_wstd_eq::cBinop_INwO6uqs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WYGuv6iW, HV_BINOP_MULTIPLY, 0, m, &cBinop_WYGuv6iW_sendMessage);
}

void Heavy_wstd_eq::cBinop_wkExSnKx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_JhyABx1l_sendMessage);
}

void Heavy_wstd_eq::cBinop_JhyABx1l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Nu4xUpUB_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_tM2GAd8V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_q8L8vFfR, HV_BINOP_MULTIPLY, 1, m, &cBinop_q8L8vFfR_sendMessage);
}

void Heavy_wstd_eq::cMsg_m7JvLqjE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_J8Qi4x5X_sendMessage);
}

void Heavy_wstd_eq::cBinop_J8Qi4x5X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_tM2GAd8V_sendMessage);
}

void Heavy_wstd_eq::cMsg_j9IXKslj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_xH7qODvf_sendMessage);
}

void Heavy_wstd_eq::cBinop_xH7qODvf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CBTZgbrJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_CBTZgbrJ_sendMessage);
}

void Heavy_wstd_eq::cBinop_lAOdfVA8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eZwyFlxb, HV_BINOP_MULTIPLY, 1, m, &cBinop_eZwyFlxb_sendMessage);
}

void Heavy_wstd_eq::cMsg_L0RAnJ8P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_EBXh6fZ6_sendMessage);
}

void Heavy_wstd_eq::cBinop_EBXh6fZ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_lAOdfVA8_sendMessage);
}

void Heavy_wstd_eq::cBinop_ECtZgIuB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oXBuPGm4, 1, m, &cVar_oXBuPGm4_sendMessage);
}

void Heavy_wstd_eq::cBinop_CInjeMSE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HF5Xz6be, HV_BINOP_MULTIPLY, 1, m, &cBinop_HF5Xz6be_sendMessage);
}

void Heavy_wstd_eq::cMsg_OGPN9lhh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_IKroeWCf_sendMessage);
}

void Heavy_wstd_eq::cBinop_IKroeWCf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ibSDkDog, HV_BINOP_MULTIPLY, 1, m, &cBinop_ibSDkDog_sendMessage);
}

void Heavy_wstd_eq::cVar_oXBuPGm4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aSvTW660_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cVar_YKmnTCqa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yjPFrrqP_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_srbUcmkD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VJDcd0wu_sendMessage);
}

void Heavy_wstd_eq::cVar_0z1LE9Yi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_wkExSnKx_sendMessage);
}

void Heavy_wstd_eq::cCast_dgB9rayk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_S5zge05a_sendMessage);
}

void Heavy_wstd_eq::cCast_erLvrMrw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_Jue56Jwn_sendMessage);
}

void Heavy_wstd_eq::cSend_5hzq7DgX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_MuBRdKud_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_OrEPuIp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_IpydDhpX_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_NfAUHqsG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_t9ei2NTX_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_Nu4xUpUB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_88Dmd7Pe_sendMessage);
}

void Heavy_wstd_eq::cBinop_88Dmd7Pe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_laXBezeo, HV_BINOP_MULTIPLY, 1, m, &cBinop_laXBezeo_sendMessage);
}

void Heavy_wstd_eq::cBinop_laXBezeo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_X7s2Z0eY_sendMessage);
}

void Heavy_wstd_eq::cBinop_X7s2Z0eY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_NfAUHqsG_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_aSvTW660_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_MRQczd0E_sendMessage);
}

void Heavy_wstd_eq::cBinop_MRQczd0E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OyU2zpbx_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WRMMqDl8_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BN4OVrDG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8MxL6G02_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pvhLFCNk_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nG75NDDR_sendMessage);
}

void Heavy_wstd_eq::cBinop_q8L8vFfR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_k5nkdKU9_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_CBTZgbrJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4Y1KnuqN_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_eZwyFlxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tkquMJPk_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_HF5Xz6be_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HNnKJ84o_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_ibSDkDog_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bNJzsJqY_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cCast_6z9g28jn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0z1LE9Yi, 1, m, &cVar_0z1LE9Yi_sendMessage);
}

void Heavy_wstd_eq::cCast_kstum2lK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YKmnTCqa, 0, m, &cVar_YKmnTCqa_sendMessage);
}

void Heavy_wstd_eq::cCast_OyU2zpbx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_wstd_eq::cCast_BN4OVrDG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HF5Xz6be, HV_BINOP_MULTIPLY, 0, m, &cBinop_HF5Xz6be_sendMessage);
}

void Heavy_wstd_eq::cCast_nG75NDDR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_q8L8vFfR, HV_BINOP_MULTIPLY, 0, m, &cBinop_q8L8vFfR_sendMessage);
}

void Heavy_wstd_eq::cCast_WRMMqDl8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ibSDkDog, HV_BINOP_MULTIPLY, 0, m, &cBinop_ibSDkDog_sendMessage);
}

void Heavy_wstd_eq::cCast_pvhLFCNk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CBTZgbrJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_CBTZgbrJ_sendMessage);
}

void Heavy_wstd_eq::cCast_8MxL6G02_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eZwyFlxb, HV_BINOP_MULTIPLY, 0, m, &cBinop_eZwyFlxb_sendMessage);
}

void Heavy_wstd_eq::cCast_VJDcd0wu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oXBuPGm4, 0, m, &cVar_oXBuPGm4_sendMessage);
}

void Heavy_wstd_eq::cCast_yjPFrrqP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0z1LE9Yi, 0, m, &cVar_0z1LE9Yi_sendMessage);
}

void Heavy_wstd_eq::cMsg_KsUDKBqk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Lkkymjs2, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_UI7pz3Zg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_bwBUaRYx, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_2XA2Wdxo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_r61uHlAq, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_LM91crs6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ezlLygMw, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_n93Se1rq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_cDIjLYjB, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_LOQ0zOAZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Fqm3wkNE_sendMessage);
}

void Heavy_wstd_eq::cSystem_Fqm3wkNE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mtOZtVkP, HV_BINOP_DIVIDE, 1, m, &cBinop_mtOZtVkP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bA38kkoq_sendMessage);
}

void Heavy_wstd_eq::cUnop_iOPpQMQZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_7eeQnrMt_sendMessage);
}

void Heavy_wstd_eq::cMsg_6zI38mtk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_iOPpQMQZ_sendMessage);
}

void Heavy_wstd_eq::cBinop_7eeQnrMt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mtOZtVkP, HV_BINOP_DIVIDE, 0, m, &cBinop_mtOZtVkP_sendMessage);
}

void Heavy_wstd_eq::cCast_bA38kkoq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6zI38mtk_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_mtOZtVkP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8cW4DKPu, HV_BINOP_MULTIPLY, 1, m, &cBinop_8cW4DKPu_sendMessage);
}

void Heavy_wstd_eq::cBinop_8cW4DKPu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nLg8cSck_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OYgi1ozt_sendMessage);
}

void Heavy_wstd_eq::cUnop_T5qZZvox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Nie6fVgj_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cUnop_Yg7Qf5mB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_sjXbvyiN_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_PAZL6SrY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_lQb6tztE_sendMessage);
}

void Heavy_wstd_eq::cBinop_lQb6tztE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8cW4DKPu, HV_BINOP_MULTIPLY, 0, m, &cBinop_8cW4DKPu_sendMessage);
}

void Heavy_wstd_eq::cBinop_12xp1Det_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_SoGKYipH_sendMessage);
}

void Heavy_wstd_eq::cBinop_SoGKYipH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8r3cJdU9_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_yteyrtm7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_U9EIL4Z3, 1, m, &cVar_U9EIL4Z3_sendMessage);
}

void Heavy_wstd_eq::cVar_U9EIL4Z3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lzc7lMCJ_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_NVXRrYvg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Bt33evw5, HV_BINOP_MULTIPLY, 1, m, &cBinop_Bt33evw5_sendMessage);
}

void Heavy_wstd_eq::cBinop_qIMa1gv0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_NVXRrYvg_sendMessage);
}

void Heavy_wstd_eq::cBinop_cF1t8UAA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_RHyEXnnz_sendMessage);
}

void Heavy_wstd_eq::cBinop_RHyEXnnz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XITMzzAs, HV_BINOP_MULTIPLY, 1, m, &cBinop_XITMzzAs_sendMessage);
}

void Heavy_wstd_eq::cBinop_uU4Xk2Oc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_N6Bl3bI1, HV_BINOP_MULTIPLY, 1, m, &cBinop_N6Bl3bI1_sendMessage);
}

void Heavy_wstd_eq::cBinop_OsWVFbO4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_uU4Xk2Oc_sendMessage);
}

void Heavy_wstd_eq::cBinop_yU6xyaDE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pIb1LSGO, HV_BINOP_MULTIPLY, 1, m, &cBinop_pIb1LSGO_sendMessage);
}

void Heavy_wstd_eq::cMsg_QMNmfaAS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_YnuEmnrb_sendMessage);
}

void Heavy_wstd_eq::cBinop_YnuEmnrb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0scmuTe2, HV_BINOP_MULTIPLY, 1, m, &cBinop_0scmuTe2_sendMessage);
}

void Heavy_wstd_eq::cVar_WWNkb1Bs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_062snjHf_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_PAZL6SrY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BAlo9jAJ_sendMessage);
}

void Heavy_wstd_eq::cVar_1a05rG01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_12xp1Det_sendMessage);
}

void Heavy_wstd_eq::cCast_nLg8cSck_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_T5qZZvox_sendMessage);
}

void Heavy_wstd_eq::cCast_OYgi1ozt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_Yg7Qf5mB_sendMessage);
}

void Heavy_wstd_eq::cSend_Nie6fVgj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_kw7VvPAZ_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_sjXbvyiN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ahLMPlZV_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_SiihYJJG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_qf0ceDnp_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_8r3cJdU9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_1Pk8ck0B_sendMessage);
}

void Heavy_wstd_eq::cBinop_1Pk8ck0B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_t8cEVHZl, HV_BINOP_MULTIPLY, 1, m, &cBinop_t8cEVHZl_sendMessage);
}

void Heavy_wstd_eq::cBinop_t8cEVHZl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_qReOEsDM_sendMessage);
}

void Heavy_wstd_eq::cBinop_qReOEsDM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_SiihYJJG_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_lzc7lMCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_1c5wwoRb_sendMessage);
}

void Heavy_wstd_eq::cBinop_1c5wwoRb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DtDwh11R_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MSCVzDYU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_F1fgGlGM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rtfTocbV_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lD8qDbDr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_33aUaENP_sendMessage);
}

void Heavy_wstd_eq::cBinop_Bt33evw5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KsUDKBqk_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_XITMzzAs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UI7pz3Zg_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_N6Bl3bI1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2XA2Wdxo_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_pIb1LSGO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LM91crs6_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_0scmuTe2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n93Se1rq_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cCast_C6sTl2pN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WWNkb1Bs, 0, m, &cVar_WWNkb1Bs_sendMessage);
}

void Heavy_wstd_eq::cCast_tt0IcjHB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1a05rG01, 1, m, &cVar_1a05rG01_sendMessage);
}

void Heavy_wstd_eq::cCast_MSCVzDYU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0scmuTe2, HV_BINOP_MULTIPLY, 0, m, &cBinop_0scmuTe2_sendMessage);
}

void Heavy_wstd_eq::cCast_33aUaENP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Bt33evw5, HV_BINOP_MULTIPLY, 0, m, &cBinop_Bt33evw5_sendMessage);
}

void Heavy_wstd_eq::cCast_DtDwh11R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_wstd_eq::cCast_lD8qDbDr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XITMzzAs, HV_BINOP_MULTIPLY, 0, m, &cBinop_XITMzzAs_sendMessage);
}

void Heavy_wstd_eq::cCast_rtfTocbV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_N6Bl3bI1, HV_BINOP_MULTIPLY, 0, m, &cBinop_N6Bl3bI1_sendMessage);
}

void Heavy_wstd_eq::cCast_F1fgGlGM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pIb1LSGO, HV_BINOP_MULTIPLY, 0, m, &cBinop_pIb1LSGO_sendMessage);
}

void Heavy_wstd_eq::cCast_BAlo9jAJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_U9EIL4Z3, 0, m, &cVar_U9EIL4Z3_sendMessage);
}

void Heavy_wstd_eq::cCast_062snjHf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1a05rG01, 0, m, &cVar_1a05rG01_sendMessage);
}

void Heavy_wstd_eq::cMsg_9LRtlcw1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Rd1TVp0A, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_U2yZ47AI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_xAvDQ3Nm, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_PMLvNeCd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_FKdpxfW2, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_haKJIAGX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_d0DZG5N3, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_L4Cf4QJS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_TsOGu6EH, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_4S8tVRIP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XnX9UktK_sendMessage);
}

void Heavy_wstd_eq::cSystem_XnX9UktK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zrDPvaCA, HV_BINOP_DIVIDE, 1, m, &cBinop_zrDPvaCA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HvWZZxtp_sendMessage);
}

void Heavy_wstd_eq::cUnop_mZf8TfKx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_I4NZiynJ_sendMessage);
}

void Heavy_wstd_eq::cMsg_qW5IPDGb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_mZf8TfKx_sendMessage);
}

void Heavy_wstd_eq::cBinop_I4NZiynJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zrDPvaCA, HV_BINOP_DIVIDE, 0, m, &cBinop_zrDPvaCA_sendMessage);
}

void Heavy_wstd_eq::cCast_HvWZZxtp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qW5IPDGb_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_zrDPvaCA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IhSRWCIP, HV_BINOP_MULTIPLY, 1, m, &cBinop_IhSRWCIP_sendMessage);
}

void Heavy_wstd_eq::cBinop_IhSRWCIP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pgSOlgSJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sWsnhbFv_sendMessage);
}

void Heavy_wstd_eq::cUnop_KmAysB0G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_vu5UWCdz_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cUnop_juPAwtw8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_cgJikrdV_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_IKT7eAPn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_nNuQG3TY_sendMessage);
}

void Heavy_wstd_eq::cBinop_nNuQG3TY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IhSRWCIP, HV_BINOP_MULTIPLY, 0, m, &cBinop_IhSRWCIP_sendMessage);
}

void Heavy_wstd_eq::cBinop_XbE0NQuU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_Jq1UTUgE_sendMessage);
}

void Heavy_wstd_eq::cBinop_Jq1UTUgE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qY6UZsjP_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_W9CxsvPz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7R07iGd8, 1, m, &cVar_7R07iGd8_sendMessage);
}

void Heavy_wstd_eq::cVar_7R07iGd8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_h4K5e61A_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_doNRlNCL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_4TNA3UY1_sendMessage);
}

void Heavy_wstd_eq::cBinop_4TNA3UY1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SDNy4he7, HV_BINOP_MULTIPLY, 1, m, &cBinop_SDNy4he7_sendMessage);
}

void Heavy_wstd_eq::cBinop_HDuaobtk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kkT0goip, HV_BINOP_MULTIPLY, 1, m, &cBinop_kkT0goip_sendMessage);
}

void Heavy_wstd_eq::cBinop_Frh2xNVn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QcOVaU1R, HV_BINOP_MULTIPLY, 1, m, &cBinop_QcOVaU1R_sendMessage);
}

void Heavy_wstd_eq::cBinop_zcvJD3la_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xynTDDcs, HV_BINOP_MULTIPLY, 1, m, &cBinop_xynTDDcs_sendMessage);
}

void Heavy_wstd_eq::cMsg_nzr83Qqd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_Ya7trE6G_sendMessage);
}

void Heavy_wstd_eq::cBinop_Ya7trE6G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pGMEQP2I, HV_BINOP_MULTIPLY, 1, m, &cBinop_pGMEQP2I_sendMessage);
}

void Heavy_wstd_eq::cVar_j8b2cAPv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pZC7lF11_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_IKT7eAPn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XQREH7jP_sendMessage);
}

void Heavy_wstd_eq::cVar_HzIMX3C0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_XbE0NQuU_sendMessage);
}

void Heavy_wstd_eq::cCast_pgSOlgSJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_KmAysB0G_sendMessage);
}

void Heavy_wstd_eq::cCast_sWsnhbFv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_juPAwtw8_sendMessage);
}

void Heavy_wstd_eq::cSend_vu5UWCdz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_iWwDDuTr_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_cgJikrdV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Jl12oBgM_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_rDNI22f6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tU5A1rdx_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_qY6UZsjP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_1AgOh0ce_sendMessage);
}

void Heavy_wstd_eq::cBinop_1AgOh0ce_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tbQkGSMg, HV_BINOP_MULTIPLY, 1, m, &cBinop_tbQkGSMg_sendMessage);
}

void Heavy_wstd_eq::cBinop_tbQkGSMg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_foc6sKaE_sendMessage);
}

void Heavy_wstd_eq::cBinop_foc6sKaE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_rDNI22f6_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_h4K5e61A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_44hJb2MJ_sendMessage);
}

void Heavy_wstd_eq::cBinop_44hJb2MJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_drbeitCN_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Xg7VSrpw_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MSbroePM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_d6vV7c4T_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eFHGAElz_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xLyxCzT0_sendMessage);
}

void Heavy_wstd_eq::cBinop_SDNy4he7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9LRtlcw1_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_kkT0goip_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_U2yZ47AI_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_QcOVaU1R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PMLvNeCd_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_xynTDDcs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_haKJIAGX_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_pGMEQP2I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_L4Cf4QJS_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cCast_EbWsx23g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HzIMX3C0, 1, m, &cVar_HzIMX3C0_sendMessage);
}

void Heavy_wstd_eq::cCast_0J4ml7Bd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_j8b2cAPv, 0, m, &cVar_j8b2cAPv_sendMessage);
}

void Heavy_wstd_eq::cCast_MSbroePM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xynTDDcs, HV_BINOP_MULTIPLY, 0, m, &cBinop_xynTDDcs_sendMessage);
}

void Heavy_wstd_eq::cCast_Xg7VSrpw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pGMEQP2I, HV_BINOP_MULTIPLY, 0, m, &cBinop_pGMEQP2I_sendMessage);
}

void Heavy_wstd_eq::cCast_eFHGAElz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kkT0goip, HV_BINOP_MULTIPLY, 0, m, &cBinop_kkT0goip_sendMessage);
}

void Heavy_wstd_eq::cCast_drbeitCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_wstd_eq::cCast_d6vV7c4T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QcOVaU1R, HV_BINOP_MULTIPLY, 0, m, &cBinop_QcOVaU1R_sendMessage);
}

void Heavy_wstd_eq::cCast_xLyxCzT0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SDNy4he7, HV_BINOP_MULTIPLY, 0, m, &cBinop_SDNy4he7_sendMessage);
}

void Heavy_wstd_eq::cCast_XQREH7jP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7R07iGd8, 0, m, &cVar_7R07iGd8_sendMessage);
}

void Heavy_wstd_eq::cCast_pZC7lF11_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HzIMX3C0, 0, m, &cVar_HzIMX3C0_sendMessage);
}

void Heavy_wstd_eq::cMsg_MsiLTXFL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_jh2eZltk, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_QVeHZ5Go_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_tgXLWONs, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_zhJwvoZs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_iuhLneex, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_Vtb8AdtI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_wCklLQHT, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_pOGQcNIV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_fsdQXEjZ, 0, m, NULL);
}

void Heavy_wstd_eq::cMsg_rH7i7Upu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_onNXXkAC_sendMessage);
}

void Heavy_wstd_eq::cSystem_onNXXkAC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vBhrNH3l, HV_BINOP_DIVIDE, 1, m, &cBinop_vBhrNH3l_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NzibC2IL_sendMessage);
}

void Heavy_wstd_eq::cUnop_SD0U5729_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_6St7sOYB_sendMessage);
}

void Heavy_wstd_eq::cMsg_mdFIgr7c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_SD0U5729_sendMessage);
}

void Heavy_wstd_eq::cBinop_6St7sOYB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vBhrNH3l, HV_BINOP_DIVIDE, 0, m, &cBinop_vBhrNH3l_sendMessage);
}

void Heavy_wstd_eq::cCast_NzibC2IL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mdFIgr7c_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_vBhrNH3l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1Lr8mYWh, HV_BINOP_MULTIPLY, 1, m, &cBinop_1Lr8mYWh_sendMessage);
}

void Heavy_wstd_eq::cBinop_1Lr8mYWh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xCoVNFOu_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_N5ly36mU_sendMessage);
}

void Heavy_wstd_eq::cUnop_0AqyeijW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_6iDJhu4I_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cUnop_lGzR9jOR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_afSmq9Wk_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_XxUQKjbc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_76KYM0J1_sendMessage);
}

void Heavy_wstd_eq::cBinop_76KYM0J1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1Lr8mYWh, HV_BINOP_MULTIPLY, 0, m, &cBinop_1Lr8mYWh_sendMessage);
}

void Heavy_wstd_eq::cBinop_4QTOXOMY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_1cLH2zjK_sendMessage);
}

void Heavy_wstd_eq::cBinop_1cLH2zjK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YAN3dWkE_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_9rtanKrF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AG09tufW, 1, m, &cVar_AG09tufW_sendMessage);
}

void Heavy_wstd_eq::cVar_AG09tufW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_V7X8LalG_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_lxX9sbnj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_GBrBmYzD_sendMessage);
}

void Heavy_wstd_eq::cBinop_GBrBmYzD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lFWAKVMf, HV_BINOP_MULTIPLY, 1, m, &cBinop_lFWAKVMf_sendMessage);
}

void Heavy_wstd_eq::cBinop_nTQDDxwN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5RXg9iwP, HV_BINOP_MULTIPLY, 1, m, &cBinop_5RXg9iwP_sendMessage);
}

void Heavy_wstd_eq::cBinop_acugn0JB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_80DMty1O, HV_BINOP_MULTIPLY, 1, m, &cBinop_80DMty1O_sendMessage);
}

void Heavy_wstd_eq::cBinop_yDQdcAeW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sawl3pG5, HV_BINOP_MULTIPLY, 1, m, &cBinop_Sawl3pG5_sendMessage);
}

void Heavy_wstd_eq::cMsg_znmiG18d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_rsNGMsc5_sendMessage);
}

void Heavy_wstd_eq::cBinop_rsNGMsc5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WIN8T0IF, HV_BINOP_MULTIPLY, 1, m, &cBinop_WIN8T0IF_sendMessage);
}

void Heavy_wstd_eq::cVar_HFyiPOeC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Oqiy8fsE_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_XxUQKjbc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aNv7QrHh_sendMessage);
}

void Heavy_wstd_eq::cVar_atEo3NBi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_4QTOXOMY_sendMessage);
}

void Heavy_wstd_eq::cCast_xCoVNFOu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_0AqyeijW_sendMessage);
}

void Heavy_wstd_eq::cCast_N5ly36mU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_lGzR9jOR_sendMessage);
}

void Heavy_wstd_eq::cSend_6iDJhu4I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2JTdiF7f_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_afSmq9Wk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jizggOAv_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cSend_uwZEcyyB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Nj4XcvQk_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_YAN3dWkE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_bjJiccVU_sendMessage);
}

void Heavy_wstd_eq::cBinop_bjJiccVU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lSRDYTY1, HV_BINOP_MULTIPLY, 1, m, &cBinop_lSRDYTY1_sendMessage);
}

void Heavy_wstd_eq::cBinop_lSRDYTY1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_7WXpa05T_sendMessage);
}

void Heavy_wstd_eq::cBinop_7WXpa05T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_uwZEcyyB_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cMsg_V7X8LalG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_6Q0owxFw_sendMessage);
}

void Heavy_wstd_eq::cBinop_6Q0owxFw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UNsj4Ofc_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7DprvYmj_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DUoongLz_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sTIQK9Cp_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3SgRgImc_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rcysF4zw_sendMessage);
}

void Heavy_wstd_eq::cBinop_lFWAKVMf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MsiLTXFL_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_5RXg9iwP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QVeHZ5Go_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_80DMty1O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zhJwvoZs_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_Sawl3pG5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Vtb8AdtI_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_WIN8T0IF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pOGQcNIV_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cCast_diUuOqdU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_atEo3NBi, 1, m, &cVar_atEo3NBi_sendMessage);
}

void Heavy_wstd_eq::cCast_ePU2AsbL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HFyiPOeC, 0, m, &cVar_HFyiPOeC_sendMessage);
}

void Heavy_wstd_eq::cCast_DUoongLz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sawl3pG5, HV_BINOP_MULTIPLY, 0, m, &cBinop_Sawl3pG5_sendMessage);
}

void Heavy_wstd_eq::cCast_3SgRgImc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5RXg9iwP, HV_BINOP_MULTIPLY, 0, m, &cBinop_5RXg9iwP_sendMessage);
}

void Heavy_wstd_eq::cCast_7DprvYmj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WIN8T0IF, HV_BINOP_MULTIPLY, 0, m, &cBinop_WIN8T0IF_sendMessage);
}

void Heavy_wstd_eq::cCast_sTIQK9Cp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_80DMty1O, HV_BINOP_MULTIPLY, 0, m, &cBinop_80DMty1O_sendMessage);
}

void Heavy_wstd_eq::cCast_UNsj4Ofc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_wstd_eq::cCast_rcysF4zw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lFWAKVMf, HV_BINOP_MULTIPLY, 0, m, &cBinop_lFWAKVMf_sendMessage);
}

void Heavy_wstd_eq::cCast_Oqiy8fsE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_atEo3NBi, 0, m, &cVar_atEo3NBi_sendMessage);
}

void Heavy_wstd_eq::cCast_aNv7QrHh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AG09tufW, 0, m, &cVar_AG09tufW_sendMessage);
}

void Heavy_wstd_eq::cBinop_wvYnVNHU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_DlScNNaG, 0, m, &cIf_DlScNNaG_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_LiRg470r, 0, m, &cIf_LiRg470r_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 1.0f, 0, m, &cBinop_WllyN4TH_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 1.0f, 0, m, &cBinop_zR4nkHnB_sendMessage);
}

void Heavy_wstd_eq::cBinop_WllyN4TH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_DlScNNaG, 1, m, &cIf_DlScNNaG_sendMessage);
}

void Heavy_wstd_eq::cBinop_zR4nkHnB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_LiRg470r, 1, m, &cIf_LiRg470r_sendMessage);
}

void Heavy_wstd_eq::cBinop_2fLB5Mbi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Y3Q4QJER, m);
}

void Heavy_wstd_eq::cBinop_e8qtzdME_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_C0SX6XPG, 0, m, &cIf_C0SX6XPG_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_d6TBOl54, 0, m, &cIf_d6TBOl54_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 1.0f, 0, m, &cBinop_nLveqinE_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 1.0f, 0, m, &cBinop_EoPTZcO4_sendMessage);
}

void Heavy_wstd_eq::cBinop_nLveqinE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_C0SX6XPG, 1, m, &cIf_C0SX6XPG_sendMessage);
}

void Heavy_wstd_eq::cBinop_EoPTZcO4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_d6TBOl54, 1, m, &cIf_d6TBOl54_sendMessage);
}

void Heavy_wstd_eq::cBinop_KZOhDse2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_siORK6KE, m);
}

void Heavy_wstd_eq::cBinop_imHgPnsf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TMFdKxlq, 0, m, &cIf_TMFdKxlq_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_azvUkfT1, 0, m, &cIf_azvUkfT1_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 1.0f, 0, m, &cBinop_H2eChbiy_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 1.0f, 0, m, &cBinop_u8UGaY5b_sendMessage);
}

void Heavy_wstd_eq::cBinop_H2eChbiy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TMFdKxlq, 1, m, &cIf_TMFdKxlq_sendMessage);
}

void Heavy_wstd_eq::cBinop_u8UGaY5b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_azvUkfT1, 1, m, &cIf_azvUkfT1_sendMessage);
}

void Heavy_wstd_eq::cBinop_dBQfmjlY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.08f, 0, m, &cBinop_NUca74jE_sendMessage);
}

void Heavy_wstd_eq::cSend_tmjyPa6V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DpXKtl7J_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cBinop_NUca74jE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_d0UQMJbW, m);
}

void Heavy_wstd_eq::cMsg_UFVaXl5K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_X1yEL0wN, 0, m, &cVar_X1yEL0wN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_tMcdAmM7, 0, m, &cVar_tMcdAmM7_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_4PjmBRqr, 0, m, &cVar_4PjmBRqr_sendMessage);
}

void Heavy_wstd_eq::cMsg_U7K1unTI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 88.242f);
  cVar_onMessage(_c, &Context(_c)->cVar_aka7krRZ, 0, m, &cVar_aka7krRZ_sendMessage);
}

void Heavy_wstd_eq::cBinop_vrnZjPN0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_iBshO2D4_sendMessage);
}

void Heavy_wstd_eq::cBinop_iBshO2D4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_X1yEL0wN, 0, m, &cVar_X1yEL0wN_sendMessage);
}

void Heavy_wstd_eq::cBinop_sNRD6eoB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_nzHe3qwY_sendMessage);
}

void Heavy_wstd_eq::cBinop_nzHe3qwY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tMcdAmM7, 0, m, &cVar_tMcdAmM7_sendMessage);
}

void Heavy_wstd_eq::cBinop_Y6WjCK8b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_RhmfAhPb_sendMessage);
}

void Heavy_wstd_eq::cBinop_RhmfAhPb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4PjmBRqr, 0, m, &cVar_4PjmBRqr_sendMessage);
}

void Heavy_wstd_eq::cReceive_n4xZ1g6L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VkVRubP2_sendMessage(_c, 0, m);
  cMsg_Q8vl7Iqm_sendMessage(_c, 0, m);
  cMsg_KPnWLQOs_sendMessage(_c, 0, m);
  cMsg_2IBJBFZJ_sendMessage(_c, 0, m);
  cMsg_7RQyF26o_sendMessage(_c, 0, m);
  cMsg_Ev4t9BOR_sendMessage(_c, 0, m);
  cMsg_t8PU7aV5_sendMessage(_c, 0, m);
  cMsg_ozZqbJOY_sendMessage(_c, 0, m);
  cMsg_ArjhF5VC_sendMessage(_c, 0, m);
  cMsg_dwO3qcuk_sendMessage(_c, 0, m);
  cMsg_c3asxNRo_sendMessage(_c, 0, m);
  cMsg_yAuXPDNx_sendMessage(_c, 0, m);
  cMsg_DkIPQI8K_sendMessage(_c, 0, m);
  cMsg_Dm6b7ImK_sendMessage(_c, 0, m);
  cMsg_RZSFRXWn_sendMessage(_c, 0, m);
  cMsg_txb7BUsU_sendMessage(_c, 0, m);
  cMsg_qvSfaioT_sendMessage(_c, 0, m);
  cMsg_bKFO3Kq5_sendMessage(_c, 0, m);
  cMsg_XE1ToMtB_sendMessage(_c, 0, m);
  cMsg_LOQ0zOAZ_sendMessage(_c, 0, m);
  cMsg_4S8tVRIP_sendMessage(_c, 0, m);
  cMsg_rH7i7Upu_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_J73macBU, 0, m, &cVar_J73macBU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_D5AWwWQi, 0, m, &cVar_D5AWwWQi_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WKSRWc4E, 0, m, &cVar_WKSRWc4E_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_OM7PmNz7, 0, m, &cVar_OM7PmNz7_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_0vgO6XPO, 0, m, &cVar_0vgO6XPO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qgVdsg7B, 0, m, &cVar_qgVdsg7B_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_2ftN6oT1, 0, m, &cVar_2ftN6oT1_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wtME6Uov, 0, m, &cVar_wtME6Uov_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UHJrWd3R, 0, m, &cVar_UHJrWd3R_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LrDL1BTD, 0, m, &cVar_LrDL1BTD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Y9I5ZBZD, 0, m, &cVar_Y9I5ZBZD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kOHE8oTl, 0, m, &cVar_kOHE8oTl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6cafKgtk, 0, m, &cVar_6cafKgtk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_AKSUevQt, 0, m, &cVar_AKSUevQt_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_FvYqaoDT, 0, m, &cVar_FvYqaoDT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_fgj51JW5, 0, m, &cVar_fgj51JW5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vXGUJsA2, 0, m, &cVar_vXGUJsA2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Od4mGS29, 0, m, &cVar_Od4mGS29_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_YKmnTCqa, 0, m, &cVar_YKmnTCqa_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WWNkb1Bs, 0, m, &cVar_WWNkb1Bs_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_j8b2cAPv, 0, m, &cVar_j8b2cAPv_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HFyiPOeC, 0, m, &cVar_HFyiPOeC_sendMessage);
  cMsg_1ak7h0zA_sendMessage(_c, 0, m);
  cMsg_Gg7u5Lub_sendMessage(_c, 0, m);
  cMsg_UFVaXl5K_sendMessage(_c, 0, m);
  cMsg_U7K1unTI_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cReceive_lF18vsxE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_vrnZjPN0_sendMessage);
}

void Heavy_wstd_eq::cReceive_CV1Z1794_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_sNRD6eoB_sendMessage);
}

void Heavy_wstd_eq::cReceive_M2TXyEwE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_Y6WjCK8b_sendMessage);
}

void Heavy_wstd_eq::cReceive_rBH1SXV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_s49BBdiQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_s49BBdiQ_sendMessage);
}

void Heavy_wstd_eq::cReceive_Hpe5OlMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_gLCbMuBC_sendMessage);
}

void Heavy_wstd_eq::cReceive_j7jPq2xF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_416xYu1c, HV_BINOP_MULTIPLY, 1, m, &cBinop_416xYu1c_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_MmQamM5S_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_y7gNRlD8_sendMessage);
  cMsg_74ePEJJz_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cReceive_dIt4a5NB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fvLEZsSM, HV_BINOP_MULTIPLY, 0, m, &cBinop_fvLEZsSM_sendMessage);
}

void Heavy_wstd_eq::cReceive_QthhlhBD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Qc2tsHyA_sendMessage(_c, 0, m);
  cMsg_kVO9pKy5_sendMessage(_c, 0, m);
  cMsg_HARjQxYv_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_X92m6OR6_sendMessage);
}

void Heavy_wstd_eq::cReceive_jGcJLSq3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_ynlF1kpw_sendMessage);
  cMsg_HZPzXTTW_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cReceive_zI1jPosc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fQt5Xi1d, HV_BINOP_MULTIPLY, 0, m, &cBinop_fQt5Xi1d_sendMessage);
}

void Heavy_wstd_eq::cReceive_jPxWsPaX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_y3H8bU9k_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_d7kl0Hrl_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_6uev5bXS_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_u0Dglmrc_sendMessage);
}

void Heavy_wstd_eq::cReceive_ddaO1aeU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_uSiBz9gF_sendMessage);
  cMsg_jGSPKbHm_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cReceive_Z6Ndq3Jq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DrIJ0Q96, HV_BINOP_MULTIPLY, 0, m, &cBinop_DrIJ0Q96_sendMessage);
}

void Heavy_wstd_eq::cReceive_WgeSZZCR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_6aPx0swC_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_1d0g2CAg_sendMessage);
}

void Heavy_wstd_eq::cReceive_ZyGIg4II_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_BzuNBnuM_sendMessage);
  cMsg_aA1TdXwB_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_uphfnGWi_sendMessage);
  cMsg_JzLWzUVe_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cReceive_bgT2vYno_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JTfULxjQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_JTfULxjQ_sendMessage);
}

void Heavy_wstd_eq::cReceive_7QVuGES2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_hzEtKm98_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_2TlxrnYh_sendMessage);
}

void Heavy_wstd_eq::cReceive_YduBgfRN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_TFIcJKuo_sendMessage);
  cMsg_AVE1gIfa_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_L4ODBZkF_sendMessage);
  cMsg_BPxgaXWU_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cReceive_33E0d4rY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_88DxliJP, HV_BINOP_MULTIPLY, 0, m, &cBinop_88DxliJP_sendMessage);
}

void Heavy_wstd_eq::cReceive_iNu0k2ff_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_yLrnMoXp_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_vq9FpjWo_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_0gzuQeZy_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_FtdnMwbi_sendMessage);
}

void Heavy_wstd_eq::cReceive_rthEiND4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_P57jGLO8_sendMessage);
  cMsg_OlPOpT5I_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cReceive_KYDt84Ro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jgSUHfZ7, HV_BINOP_MULTIPLY, 0, m, &cBinop_jgSUHfZ7_sendMessage);
}

void Heavy_wstd_eq::cReceive_6vAmuSge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KAqe9174_sendMessage(_c, 0, m);
  cMsg_ZA5LE6fn_sendMessage(_c, 0, m);
  cMsg_GNztKx2Y_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_VgYnpMCM_sendMessage);
}

void Heavy_wstd_eq::cReceive_73juy3Xb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_yfPrKNby_sendMessage);
  cMsg_eXMT3rCy_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cReceive_nNBLp2Nq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZQEsxKv0, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZQEsxKv0_sendMessage);
}

void Heavy_wstd_eq::cReceive_4cFShlWc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_omkxy7mg_sendMessage(_c, 0, m);
  cMsg_wjZha833_sendMessage(_c, 0, m);
  cMsg_NEtL5DZ2_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_HBPGjuH3_sendMessage);
}

void Heavy_wstd_eq::cReceive_bTtX2kwY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_XfajgK7U_sendMessage);
  cMsg_GRBUwJ1t_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cReceive_zHCsvsj9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Gi5LFuwg, HV_BINOP_MULTIPLY, 0, m, &cBinop_Gi5LFuwg_sendMessage);
}

void Heavy_wstd_eq::cReceive_nm3v15OR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_ZfZvgvJq_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_SWzHe0Gf_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_mVYuwhiF_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_7gQCGeLk_sendMessage);
}

void Heavy_wstd_eq::cReceive_Mq44tTwd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Bd8LIp7Q_sendMessage);
  cMsg_3JEObmNQ_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cReceive_n2oVsFbE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SAfHMsrP, HV_BINOP_MULTIPLY, 0, m, &cBinop_SAfHMsrP_sendMessage);
}

void Heavy_wstd_eq::cReceive_2xlVqp3A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_SzHVyKpN_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_RZIIgPvT_sendMessage);
}

void Heavy_wstd_eq::cReceive_SfXKgWyS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_WI0lO5R6_sendMessage);
  cMsg_yD4eigky_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_rP16iscJ_sendMessage);
  cMsg_rUWulaA7_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cReceive_nlps4aOb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nHyDxMcg, HV_BINOP_MULTIPLY, 0, m, &cBinop_nHyDxMcg_sendMessage);
}

void Heavy_wstd_eq::cReceive_Ut0X5B68_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_o8Pwxec3_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_ulwUaAJA_sendMessage);
}

void Heavy_wstd_eq::cReceive_WNsvIoQ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_LdtRDBTd_sendMessage);
  cMsg_WCHnJOVY_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_ypC3c8Zh_sendMessage);
  cMsg_wUhNmgs6_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cReceive_DpXKtl7J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wtME6Uov, 0, m, &cVar_wtME6Uov_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LrDL1BTD, 0, m, &cVar_LrDL1BTD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Y9I5ZBZD, 0, m, &cVar_Y9I5ZBZD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_YKmnTCqa, 0, m, &cVar_YKmnTCqa_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_j8b2cAPv, 0, m, &cVar_j8b2cAPv_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HFyiPOeC, 0, m, &cVar_HFyiPOeC_sendMessage);
}

void Heavy_wstd_eq::cReceive_AkuwnIdf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_X1yEL0wN, 0, m, &cVar_X1yEL0wN_sendMessage);
}

void Heavy_wstd_eq::cReceive_a0Pt8Ir0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tMcdAmM7, 0, m, &cVar_tMcdAmM7_sendMessage);
}

void Heavy_wstd_eq::cReceive_R7plTYhA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4PjmBRqr, 0, m, &cVar_4PjmBRqr_sendMessage);
}

void Heavy_wstd_eq::cReceive_N6KwVPR4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FIw8K2uG, HV_BINOP_MULTIPLY, 0, m, &cBinop_FIw8K2uG_sendMessage);
}

void Heavy_wstd_eq::cReceive_e4xZa6W7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_KM2uehSJ_sendMessage);
}

void Heavy_wstd_eq::cReceive_4VhP27dD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qsU3nQFg, HV_BINOP_MULTIPLY, 1, m, &cBinop_qsU3nQFg_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_WLHYsnu4_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Aca3QYak_sendMessage);
  cMsg_omLrhg5v_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cReceive_v0Lmm0An_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GL1LG7TI, HV_BINOP_MULTIPLY, 0, m, &cBinop_GL1LG7TI_sendMessage);
}

void Heavy_wstd_eq::cReceive_hYrx8yU2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TCpPBKxV_sendMessage(_c, 0, m);
  cMsg_PTU8H6lW_sendMessage(_c, 0, m);
  cMsg_paxIuIK5_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_5CalOhTS_sendMessage);
}

void Heavy_wstd_eq::cReceive_8WiVvIXd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_W6DFDXye_sendMessage);
  cMsg_pMz9Gi9s_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cReceive_ArHUBWem_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tkFA5dwr, HV_BINOP_MULTIPLY, 0, m, &cBinop_tkFA5dwr_sendMessage);
}

void Heavy_wstd_eq::cReceive_WAD84sPX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_dTQA2YUT_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_K9nB2L42_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_TNkl6rKw_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_g4ZurPCj_sendMessage);
}

void Heavy_wstd_eq::cReceive_95yoQY2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_FLd9FElP_sendMessage);
  cMsg_BK4HB5iy_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cReceive_JRP6DdMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OfJnEpyj, HV_BINOP_MULTIPLY, 0, m, &cBinop_OfJnEpyj_sendMessage);
}

void Heavy_wstd_eq::cReceive_Rqlf3Jtm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_cex0ZnPy_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_YRBkuIKT_sendMessage);
}

void Heavy_wstd_eq::cReceive_16ZPDNVW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_LAx7tpzV_sendMessage);
  cMsg_3pw7bWCm_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Ka2KeOy7_sendMessage);
  cMsg_vgdywLKA_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cReceive_Re5Pa0dr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CuDWHqcF, HV_BINOP_MULTIPLY, 0, m, &cBinop_CuDWHqcF_sendMessage);
}

void Heavy_wstd_eq::cReceive_JMsEdRae_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_k8kINi8s_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_pe4dNYW6_sendMessage);
}

void Heavy_wstd_eq::cReceive_JcgcQDY4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_epzatWDB_sendMessage);
  cMsg_smf8gIo3_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_8veZDglL_sendMessage);
  cMsg_LE3U1ghe_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cReceive_IqkvICmX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8eaZgnn4, HV_BINOP_MULTIPLY, 0, m, &cBinop_8eaZgnn4_sendMessage);
}

void Heavy_wstd_eq::cReceive_beA3dDhm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_JFR1t0Dj_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_dSAVtgeP_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_u5iBDUfh_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_KuXHerUd_sendMessage);
}

void Heavy_wstd_eq::cReceive_OVFX62Nq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_ruNUAnj7_sendMessage);
  cMsg_n1QyUYnr_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cReceive_Ooo2CFxB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SY7kozBK, HV_BINOP_MULTIPLY, 0, m, &cBinop_SY7kozBK_sendMessage);
}

void Heavy_wstd_eq::cReceive_D1klMwit_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Wjfazvpf_sendMessage(_c, 0, m);
  cMsg_yhDCCyiS_sendMessage(_c, 0, m);
  cMsg_XI9iVA6x_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_Vt6hkxMR_sendMessage);
}

void Heavy_wstd_eq::cReceive_bbigd7Ie_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_8rsm7o9e_sendMessage);
  cMsg_AJ5v4o4g_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cReceive_MuBRdKud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_laXBezeo, HV_BINOP_MULTIPLY, 0, m, &cBinop_laXBezeo_sendMessage);
}

void Heavy_wstd_eq::cReceive_IpydDhpX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m7JvLqjE_sendMessage(_c, 0, m);
  cMsg_j9IXKslj_sendMessage(_c, 0, m);
  cMsg_L0RAnJ8P_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_CInjeMSE_sendMessage);
}

void Heavy_wstd_eq::cReceive_t9ei2NTX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_ECtZgIuB_sendMessage);
  cMsg_OGPN9lhh_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cReceive_kw7VvPAZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_t8cEVHZl, HV_BINOP_MULTIPLY, 0, m, &cBinop_t8cEVHZl_sendMessage);
}

void Heavy_wstd_eq::cReceive_ahLMPlZV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_qIMa1gv0_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_cF1t8UAA_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_OsWVFbO4_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_yU6xyaDE_sendMessage);
}

void Heavy_wstd_eq::cReceive_qf0ceDnp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_yteyrtm7_sendMessage);
  cMsg_QMNmfaAS_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cReceive_iWwDDuTr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tbQkGSMg, HV_BINOP_MULTIPLY, 0, m, &cBinop_tbQkGSMg_sendMessage);
}

void Heavy_wstd_eq::cReceive_Jl12oBgM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_HDuaobtk_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_zcvJD3la_sendMessage);
}

void Heavy_wstd_eq::cReceive_tU5A1rdx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_W9CxsvPz_sendMessage);
  cMsg_doNRlNCL_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Frh2xNVn_sendMessage);
  cMsg_nzr83Qqd_sendMessage(_c, 0, m);
}

void Heavy_wstd_eq::cReceive_2JTdiF7f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lSRDYTY1, HV_BINOP_MULTIPLY, 0, m, &cBinop_lSRDYTY1_sendMessage);
}

void Heavy_wstd_eq::cReceive_jizggOAv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_nTQDDxwN_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_yDQdcAeW_sendMessage);
}

void Heavy_wstd_eq::cReceive_Nj4XcvQk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_9rtanKrF_sendMessage);
  cMsg_lxX9sbnj_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_acugn0JB_sendMessage);
  cMsg_znmiG18d_sendMessage(_c, 0, m);
}




/*
 * Context Process Implementation
 */

int Heavy_wstd_eq::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6;

  // input and output vars
  hv_bufferf_t O0, O1;
  hv_bufferf_t I0, I1;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    // load input buffers
    __hv_load_f(inputBuffers[0]+n, VOf(I0));
    __hv_load_f(inputBuffers[1]+n, VOf(I1));

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_varread_f(&sVarf_AB1spV1s, VOf(Bf0));
    __hv_varread_f(&sVarf_x0Q3MhOs, VOf(Bf1));
    __hv_varread_f(&sVarf_HWmdoWHt, VOf(Bf2));
    __hv_add_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_JIZCItgG, VOf(Bf0));
    __hv_line_f(&sLine_QErnWAu2, VOf(Bf1));
    __hv_line_f(&sLine_mouepVdo, VOf(Bf3));
    __hv_line_f(&sLine_1OOQyxGa, VOf(Bf4));
    __hv_line_f(&sLine_0P2v0WAj, VOf(Bf5));
    __hv_biquad_f(&sBiquad_s_HJdbwGLr, VIf(Bf2), VIf(Bf0), VIf(Bf1), VIf(Bf3), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_dIuHBYC7, VOf(Bf4));
    __hv_line_f(&sLine_2fjRtvkO, VOf(Bf3));
    __hv_line_f(&sLine_kJMyAj6v, VOf(Bf1));
    __hv_line_f(&sLine_uR2KHnk8, VOf(Bf0));
    __hv_line_f(&sLine_dEzpSIr6, VOf(Bf2));
    __hv_biquad_f(&sBiquad_s_P4VzCk6R, VIf(Bf5), VIf(Bf4), VIf(Bf3), VIf(Bf1), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_TJ7GUUQc, VOf(Bf0));
    __hv_line_f(&sLine_p0AND5Yy, VOf(Bf1));
    __hv_line_f(&sLine_snMtXBTZ, VOf(Bf3));
    __hv_line_f(&sLine_9OMPI0DS, VOf(Bf4));
    __hv_line_f(&sLine_ehkIgxvU, VOf(Bf5));
    __hv_biquad_f(&sBiquad_s_lZy7VKa9, VIf(I0), VIf(Bf0), VIf(Bf1), VIf(Bf3), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_CxcHIV8W, VOf(Bf4));
    __hv_line_f(&sLine_wcAHchiR, VOf(Bf3));
    __hv_line_f(&sLine_AaO6zPYS, VOf(Bf1));
    __hv_line_f(&sLine_PLF4KN1h, VOf(Bf0));
    __hv_line_f(&sLine_8WloziL8, VOf(Bf6));
    __hv_biquad_f(&sBiquad_s_FVCwx8nw, VIf(Bf5), VIf(Bf4), VIf(Bf3), VIf(Bf1), VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_ZBSdFStx, VOf(Bf0));
    __hv_line_f(&sLine_DhBlLOfS, VOf(Bf1));
    __hv_line_f(&sLine_t0cetnap, VOf(Bf3));
    __hv_line_f(&sLine_1jKM1RTJ, VOf(Bf4));
    __hv_line_f(&sLine_2r6UQ34S, VOf(Bf5));
    __hv_biquad_f(&sBiquad_s_VBMpXW4l, VIf(Bf6), VIf(Bf0), VIf(Bf1), VIf(Bf3), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_331DZIFI, VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varwrite_f(&sVarf_AB1spV1s, VIf(Bf4));
    __hv_line_f(&sLine_6GMOfG4G, VOf(Bf4));
    __hv_zero_f(VOf(Bf5));
    __hv_line_f(&sLine_mZQBFoqC, VOf(Bf3));
    __hv_line_f(&sLine_hYO8Bq9A, VOf(Bf1));
    __hv_line_f(&sLine_EoITFEqD, VOf(Bf0));
    __hv_biquad_f(&sBiquad_s_9SKvwAbC, VIf(I0), VIf(Bf4), VIf(Bf5), VIf(Bf3), VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_sH8Jxj6n, VOf(Bf1));
    __hv_line_f(&sLine_ovVX7LkW, VOf(Bf3));
    __hv_line_f(&sLine_NODZkFYZ, VOf(Bf5));
    __hv_line_f(&sLine_dFLvO4VQ, VOf(Bf4));
    __hv_line_f(&sLine_ZqQJqLSi, VOf(Bf6));
    __hv_biquad_f(&sBiquad_s_3XSDtuwk, VIf(Bf0), VIf(Bf1), VIf(Bf3), VIf(Bf5), VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_8JIfwbyB, VOf(Bf4));
    __hv_line_f(&sLine_8ww4EGGu, VOf(Bf5));
    __hv_line_f(&sLine_4d0LKZ3d, VOf(Bf3));
    __hv_line_f(&sLine_R2CAJFYM, VOf(Bf1));
    __hv_line_f(&sLine_tzGiGQWr, VOf(Bf0));
    __hv_biquad_f(&sBiquad_s_Xmh66GYa, VIf(Bf6), VIf(Bf4), VIf(Bf5), VIf(Bf3), VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_k6PyfFD5, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_f(&sVarf_x0Q3MhOs, VIf(Bf1));
    __hv_line_f(&sLine_lv85JNTU, VOf(Bf1));
    __hv_line_f(&sLine_ugXoyMlg, VOf(Bf0));
    __hv_line_f(&sLine_C39A06R9, VOf(Bf3));
    __hv_line_f(&sLine_JyEr8Y3C, VOf(Bf5));
    __hv_line_f(&sLine_ja0JIiAC, VOf(Bf4));
    __hv_biquad_f(&sBiquad_s_edcgEzxw, VIf(I0), VIf(Bf1), VIf(Bf0), VIf(Bf3), VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_kc5oHDBt, VOf(Bf5));
    __hv_line_f(&sLine_UUKTXyyf, VOf(Bf3));
    __hv_line_f(&sLine_MV2J712n, VOf(Bf0));
    __hv_line_f(&sLine_HJ9AyKrd, VOf(Bf1));
    __hv_line_f(&sLine_Y1P2AAAW, VOf(Bf6));
    __hv_biquad_f(&sBiquad_s_J8ndMwwZ, VIf(Bf4), VIf(Bf5), VIf(Bf3), VIf(Bf0), VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_PjyqLr0E, VOf(Bf1));
    __hv_line_f(&sLine_WhPyEO3R, VOf(Bf0));
    __hv_line_f(&sLine_5RG3o5Lh, VOf(Bf3));
    __hv_line_f(&sLine_G1ysAmHZ, VOf(Bf5));
    __hv_line_f(&sLine_OzTercbZ, VOf(Bf4));
    __hv_biquad_f(&sBiquad_s_aWsuVZI8, VIf(Bf6), VIf(Bf1), VIf(Bf0), VIf(Bf3), VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_Gbdsmap3, VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varwrite_f(&sVarf_HWmdoWHt, VIf(Bf5));
    __hv_add_f(VIf(Bf2), VIf(O0), VOf(O0));
    __hv_varread_f(&sVarf_ZJTklZXC, VOf(Bf2));
    __hv_varread_f(&sVarf_JtAjI1rH, VOf(Bf5));
    __hv_varread_f(&sVarf_i1dw7hND, VOf(Bf4));
    __hv_add_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_Lkkymjs2, VOf(Bf2));
    __hv_line_f(&sLine_bwBUaRYx, VOf(Bf5));
    __hv_line_f(&sLine_r61uHlAq, VOf(Bf3));
    __hv_line_f(&sLine_ezlLygMw, VOf(Bf0));
    __hv_line_f(&sLine_cDIjLYjB, VOf(Bf1));
    __hv_biquad_f(&sBiquad_s_H7k0tUos, VIf(Bf4), VIf(Bf2), VIf(Bf5), VIf(Bf3), VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_EHa9ktCW, VOf(Bf0));
    __hv_line_f(&sLine_U9fDmIJ3, VOf(Bf3));
    __hv_line_f(&sLine_Ue3T7NXd, VOf(Bf5));
    __hv_line_f(&sLine_ruVvxswo, VOf(Bf2));
    __hv_line_f(&sLine_l3fYti6K, VOf(Bf4));
    __hv_biquad_f(&sBiquad_s_US40KNpM, VIf(Bf1), VIf(Bf0), VIf(Bf3), VIf(Bf5), VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_8tMwStS8, VOf(Bf2));
    __hv_line_f(&sLine_8yBMw5rJ, VOf(Bf5));
    __hv_line_f(&sLine_RIWIBagb, VOf(Bf3));
    __hv_line_f(&sLine_w7wZGwm5, VOf(Bf0));
    __hv_line_f(&sLine_uCx77GAz, VOf(Bf1));
    __hv_biquad_f(&sBiquad_s_5THKSpKG, VIf(I1), VIf(Bf2), VIf(Bf5), VIf(Bf3), VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_Rd1TVp0A, VOf(Bf0));
    __hv_line_f(&sLine_xAvDQ3Nm, VOf(Bf3));
    __hv_line_f(&sLine_FKdpxfW2, VOf(Bf5));
    __hv_line_f(&sLine_d0DZG5N3, VOf(Bf2));
    __hv_line_f(&sLine_TsOGu6EH, VOf(Bf6));
    __hv_biquad_f(&sBiquad_s_VVDknN9F, VIf(Bf1), VIf(Bf0), VIf(Bf3), VIf(Bf5), VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_vq700BJN, VOf(Bf2));
    __hv_line_f(&sLine_i9GvfDsr, VOf(Bf5));
    __hv_line_f(&sLine_I1vncudL, VOf(Bf3));
    __hv_line_f(&sLine_rno2IaiJ, VOf(Bf0));
    __hv_line_f(&sLine_HgwSifwP, VOf(Bf1));
    __hv_biquad_f(&sBiquad_s_64S6uzOR, VIf(Bf6), VIf(Bf2), VIf(Bf5), VIf(Bf3), VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_Y3Q4QJER, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varwrite_f(&sVarf_ZJTklZXC, VIf(Bf0));
    __hv_line_f(&sLine_RYOuD3Q5, VOf(Bf0));
    __hv_zero_f(VOf(Bf1));
    __hv_line_f(&sLine_PdYbzBRQ, VOf(Bf3));
    __hv_line_f(&sLine_7pUpOcxF, VOf(Bf5));
    __hv_line_f(&sLine_DlsYGLDY, VOf(Bf2));
    __hv_biquad_f(&sBiquad_s_5ZEDhamU, VIf(I1), VIf(Bf0), VIf(Bf1), VIf(Bf3), VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_1RKzYP4D, VOf(Bf5));
    __hv_line_f(&sLine_2jjh3cna, VOf(Bf3));
    __hv_line_f(&sLine_H5JewrOc, VOf(Bf1));
    __hv_line_f(&sLine_NbX7M5TN, VOf(Bf0));
    __hv_line_f(&sLine_q34UGJYK, VOf(Bf6));
    __hv_biquad_f(&sBiquad_s_1QZZZnf3, VIf(Bf2), VIf(Bf5), VIf(Bf3), VIf(Bf1), VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_nLfKhxvm, VOf(Bf0));
    __hv_line_f(&sLine_zzqm33Vi, VOf(Bf1));
    __hv_line_f(&sLine_jeFy1iqT, VOf(Bf3));
    __hv_line_f(&sLine_IIerTTpM, VOf(Bf5));
    __hv_line_f(&sLine_e1eH3MOt, VOf(Bf2));
    __hv_biquad_f(&sBiquad_s_aeT5TR0x, VIf(Bf6), VIf(Bf0), VIf(Bf1), VIf(Bf3), VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_d0UQMJbW, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varwrite_f(&sVarf_JtAjI1rH, VIf(Bf5));
    __hv_line_f(&sLine_VPXdhIMd, VOf(Bf5));
    __hv_line_f(&sLine_mNjNpQGS, VOf(Bf2));
    __hv_line_f(&sLine_WcJcmCe9, VOf(Bf3));
    __hv_line_f(&sLine_spjpFrne, VOf(Bf1));
    __hv_line_f(&sLine_ObqsHhQG, VOf(Bf0));
    __hv_biquad_f(&sBiquad_s_WHveOMFt, VIf(I1), VIf(Bf5), VIf(Bf2), VIf(Bf3), VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_jh2eZltk, VOf(Bf1));
    __hv_line_f(&sLine_tgXLWONs, VOf(Bf3));
    __hv_line_f(&sLine_iuhLneex, VOf(Bf2));
    __hv_line_f(&sLine_wCklLQHT, VOf(Bf5));
    __hv_line_f(&sLine_fsdQXEjZ, VOf(Bf6));
    __hv_biquad_f(&sBiquad_s_zlmdiRBF, VIf(Bf0), VIf(Bf1), VIf(Bf3), VIf(Bf2), VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_3AuKKgR1, VOf(Bf5));
    __hv_line_f(&sLine_bcwFn5rP, VOf(Bf2));
    __hv_line_f(&sLine_f32Mh9jI, VOf(Bf3));
    __hv_line_f(&sLine_bG3mC0oE, VOf(Bf1));
    __hv_line_f(&sLine_VaVXtgnd, VOf(Bf0));
    __hv_biquad_f(&sBiquad_s_ipbCpSF5, VIf(Bf6), VIf(Bf5), VIf(Bf2), VIf(Bf3), VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_siORK6KE, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_f(&sVarf_i1dw7hND, VIf(Bf1));
    __hv_add_f(VIf(Bf4), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_wstd_eq::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 2 channel(s)
  float **const bIn = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bIn[0] = inputBuffers+(0*n4);
  bIn[1] = inputBuffers+(1*n4);

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_wstd_eq::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 2 channel(s), uninterleave
  float *const bIn = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));
  #if HV_SIMD_SSE || HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 a = _mm_load_ps(inputBuffers+i);                // LRLR
    __m128 b = _mm_load_ps(inputBuffers+4+i);              // LRLR
    __m128 x = _mm_shuffle_ps(a, b, _MM_SHUFFLE(2,0,2,0)); // LLLL
    __m128 y = _mm_shuffle_ps(a, b, _MM_SHUFFLE(3,1,3,1)); // RRRR
    _mm_store_ps(bIn+j, x);
    _mm_store_ps(bIn+n4+j, y);
  }
  #elif HV_SIMD_NEON
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4x2_t a = vld2q_f32(inputBuffers+i); // load and uninterleave
    vst1q_f32(bIn+j, a.val[0]);
    vst1q_f32(bIn+n4+j, a.val[1]);
  }
  #else // HV_SIMD_NONE
  for (int j = 0; j < n4; ++j) {
    bIn[0*n4+j] = inputBuffers[0+2*j];
    bIn[1*n4+j] = inputBuffers[1+2*j];
  }
  #endif

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}
