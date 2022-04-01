/*
 * File: look2_iu16s16lu16n16ts16Ds32ds32_binlcas.c
 *
 * Code generated for Simulink model 'Sokon_X01_Cmf'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:15:07 2022
 */

#include "rtwtypes.h"
#include "asr_s32.h"
#include "look2_iu16s16lu16n16ts16Ds32ds32_binlcas.h"

int16_T look2_iu16s16lu16n16ts16Ds32ds32_binlcas(uint16_T u0, int16_T u1, const
  uint16_T bp0[], const int16_T bp1[], const int16_T table[], const uint32_T
  maxIndex[], uint32_T stride)
{
  int16_T y;
  uint16_T frac;
  uint32_T bpIndices[2];
  uint16_T fractions[2];
  int16_T yR_1d;
  uint32_T iRght;
  uint32_T bpIdx;
  uint32_T iLeft;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0U;
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = (maxIndex[0U] >> 1U);
    iLeft = 0U;
    iRght = maxIndex[0U];
    while ((iRght - iLeft) > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = ((iRght + iLeft) >> 1U);
    }

    frac = (uint16_T)((((uint32_T)((uint16_T)(((uint32_T)u0) - ((uint32_T)
      bp0[iLeft])))) << 16) / ((uint32_T)((uint16_T)(((uint32_T)bp0[iLeft + 1U])
      - ((uint32_T)bp0[iLeft])))));
  } else {
    iLeft = maxIndex[0U];
    frac = 0U;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = 0U;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = (maxIndex[1U] >> 1U);
    iLeft = 0U;
    iRght = maxIndex[1U];
    while ((iRght - iLeft) > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = ((iRght + iLeft) >> 1U);
    }

    frac = (uint16_T)((((uint32_T)((uint16_T)((int32_T)(((int32_T)u1) -
      ((int32_T)bp1[iLeft]))))) << 16) / ((uint32_T)((uint16_T)((int32_T)
      (((int32_T)bp1[iLeft + 1U]) - ((int32_T)bp1[iLeft]))))));
  } else {
    iLeft = maxIndex[1U];
    frac = 0U;
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  bpIdx = (iLeft * stride) + bpIndices[0U];
  if (bpIndices[0U] == maxIndex[0U]) {
    y = table[bpIdx];
  } else {
    y = (int16_T)(((int16_T)asr_s32((((int32_T)table[bpIdx + 1U]) - ((int32_T)
      table[bpIdx])) * ((int32_T)fractions[0U]), 16U)) + table[bpIdx]);
  }

  if (iLeft == maxIndex[1U]) {
  } else {
    bpIdx += stride;
    if (bpIndices[0U] == maxIndex[0U]) {
      yR_1d = table[bpIdx];
    } else {
      yR_1d = (int16_T)(((int16_T)asr_s32((((int32_T)table[bpIdx + 1U]) -
        ((int32_T)table[bpIdx])) * ((int32_T)fractions[0U]), 16U)) + table[bpIdx]);
    }

    y += (int16_T)asr_s32((((int32_T)yR_1d) - ((int32_T)y)) * ((int32_T)frac),
                          16U);
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
