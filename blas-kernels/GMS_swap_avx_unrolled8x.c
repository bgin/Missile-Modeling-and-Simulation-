

#include <immintrin.h>
#include <omp.h>
#include "GMS_swap_avx_unrolled8x.h"
#include "GMS_blas_kernels_defs.h"


void
sswap_u_ymm8r4_unroll8x( const int32_t n,
		        float * __restrict x,
			const int32_t incx,
			float * __restrict y,
			const int32_t incy) {
					  
                        if(__builtin_expect(0==n,0)) {return;}
			__ATTR_ALIGN__(32) __m256 xv[8];
			__ATTR_ALIGN__(32) __m256 yv[8];
			int32_t i;

			if(__builtin_expect(1==incx,1) &&
			   __builtin_expect(1==incy,1)) {

			   for(i = 0; (i+63) < n; i += 64) {
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                               _mm_prefetch((const char*)&x[i+16],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+16],_MM_HINT_T0);
                               xv[0] = _mm256_loadu_ps(&x[i+0]);
			       yv[0] = _mm256_loadu_ps(&y[i+0]);
			       _mm256_storeu_ps(&x[i+0],yv[0]);
			       _mm256_storeu_ps(&y[i+0],xv[0]);
			       xv[1] = _mm256_loadu_ps(&x[i+8]);
			       yv[1] = _mm256_loadu_ps(&y[i+8]);
			       _mm256_storeu_ps(&x[i+8],yv[1]);
			       _mm256_storeu_ps(&y[i+8],xv[1]);
			       _mm_prefetch((const char*)&x[i+32],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+32],_MM_HINT_T0);
			       xv[2] = _mm256_loadu_ps(&x[i+16]);
			       yv[2] = _mm256_loadu_ps(&y[i+16]);
			       _mm256_storeu_ps(&x[i+16],yv[2]);
			       _mm256_storeu_ps(&y[i+16],xv[2]);
			       xv[3] = _mm256_loadu_ps(&x[i+24]);
			       yv[3] = _mm256_loadu_ps(&y[i+24]);
			       _mm256_storeu_ps(&x[i+24],yv[3]);
			       _mm256_storeu_ps(&y[i+24],xv[3]);
			       _mm_prefetch((const char*)&x[i+48],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+48],_MM_HINT_T0);
			       xv[4] = _mm256_loadu_ps(&x[i+32]);
			       yv[4] = _mm256_loadu_ps(&y[i+32]);
			       _mm256_storeu_ps(&x[i+32],yv[4]);
			       _mm256_storeu_ps(&y[i+32],xv[4]);
			       xv[5] = _mm256_loadu_ps(&x[i+40]);
			       yv[5] = _mm256_loadu_ps(&y[i+40]);
			       _mm256_storeu_ps(&x[i+40],yv[5]);
			       _mm256_storeu_ps(&y[i+40],xv[5]);
			       _mm_prefetch((const char*)&x[i+64],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+64],_MM_HINT_T0);
			       xv[6] = _mm256_loadu_ps(&x[i+48]);
			       yv[6] = _mm256_loadu_ps(&y[i+48]);
			       _mm256_storeu_ps(&x[i+48],yv[6]);
			       _mm256_storeu_ps(&y[i+48],xv[6]);
			       xv[7] = _mm256_loadu_ps(&x[i+56]);
			       yv[7] = _mm256_loadu_ps(&y[i+56]);
			       _mm256_storeu_ps(&x[i+56],yv[7]);
			       _mm256_storeu_ps(&y[i+56],xv[7]);
			       
#else
                               _mm_prefetch((const char*)&x[i+16],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+16],_MM_HINT_T0);
			       _mm_prefetch((const char*)&x[i+32],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+32],_MM_HINT_T0);
			       _mm_prefetch((const char*)&x[i+48],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+48],_MM_HINT_T0);
			       _mm_prefetch((const char*)&x[i+64],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+64],_MM_HINT_T0);
			        xv[0] = _mm256_loadu_ps(&x[i+0]);
				xv[1] = _mm256_loadu_ps(&x[i+8]);
				xv[2] = _mm256_loadu_ps(&x[i+16]);
				xv[3] = _mm256_loadu_ps(&x[i+24]);
				xv[4] = _mm256_loadu_ps(&x[i+32]);
				xv[5] = _mm256_loadu_ps(&x[i+40]);
				xv[6] = _mm256_loadu_ps(&x[i+48]);
				xv[7] = _mm256_loadu_ps(&x[i+56]);
				yv[0] = _mm256_loadu_ps(&y[i+0]);
				yv[1] = _mm256_loadu_ps(&y[i+8]);
				yv[2] = _mm256_loadu_ps(&y[i+16]);
				yv[3] = _mm256_loadu_ps(&y[i+24]);
				yv[4] = _mm256_loadu_ps(&y[i+32]);
				yv[5] = _mm256_loadu_ps(&y[i+40]);
				yv[6] = _mm256_loadu_ps(&y[i+48]);
			        yv[7] = _mm256_loadu_ps(&y[i+56]);
				_mm256_storeu_ps(&x[i+0],yv[0]);
				_mm256_storeu_ps(&x[i+8],yv[1]);
				_mm256_storeu_ps(&x[i+16],yv[2]);
				_mm256_storeu_ps(&x[i+24],yv[3]);
				_mm256_storeu_ps(&x[i+32],yv[4]);
				_mm256_storeu_ps(&x[i+40],yv[5]);
				_mm256_storeu_ps(&x[i+48],yv[6]);
				_mm256_storeu_ps(&x[i+56],yv[7]);
				_mm256_storeu_ps(&y[i+0],xv[0]);
				_mm256_storeu_ps(&y[i+8],xv[1]);
				_mm256_storeu_ps(&y[i+16],xv[2]);
				_mm256_storeu_ps(&y[i+24],xv[3]);
				_mm256_storeu_ps(&y[i+32],xv[4]);
				_mm256_storeu_ps(&y[i+40],xv[5]);
				_mm256_storeu_ps(&y[i+48],xv[6]);
				_mm256_storeu_ps(&y[i+56],xv[7]);
				
				
#endif

			   }

			   for(; (i+31) < n; i += 32) {
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                               //_mm_prefetch((const char*)&x[i+16],_MM_HINT_T0);
			       //_mm_prefetch((const char*)&y[i+16],_MM_HINT_T0);
                               xv[0] = _mm256_loadu_ps(&x[i+0]);
			       yv[0] = _mm256_loadu_ps(&y[i+0]);
			       _mm256_storeu_ps(&x[i+0],yv[0]);
			       _mm256_storeu_ps(&y[i+0],xv[0]);
			       xv[1] = _mm256_loadu_ps(&x[i+8]);
			       yv[1] = _mm256_loadu_ps(&y[i+8]);
			       _mm256_storeu_ps(&x[i+8],yv[1]);
			       _mm256_storeu_ps(&y[i+8],xv[1]);
			       //_mm_prefetch((const char*)&x[i+32],_MM_HINT_T0);
			       //_mm_prefetch((const char*)&y[i+32],_MM_HINT_T0);
			       xv[2] = _mm256_loadu_ps(&x[i+16]);
			       yv[2] = _mm256_loadu_ps(&y[i+16]);
			       _mm256_storeu_ps(&x[i+16],yv[2]);
			       _mm256_storeu_ps(&y[i+16],xv[2]);
			       xv[3] = _mm256_loadu_ps(&x[i+24]);
			       yv[3] = _mm256_loadu_ps(&y[i+24]);
			       _mm256_storeu_ps(&x[i+24],yv[3]);
			       _mm256_storeu_ps(&y[i+24],xv[3]);
#else
                                xv[0] = _mm256_loadu_ps(&x[i+0]);
				xv[1] = _mm256_loadu_ps(&x[i+8]);
				xv[2] = _mm256_loadu_ps(&x[i+16]);
				xv[3] = _mm256_loadu_ps(&x[i+24]);
				yv[0] = _mm256_loadu_ps(&y[i+0]);
				yv[1] = _mm256_loadu_ps(&y[i+8]);
				yv[2] = _mm256_loadu_ps(&y[i+16]);
				yv[3] = _mm256_loadu_ps(&y[i+24]);
				_mm256_storeu_ps(&x[i+0],yv[0]);
				_mm256_storeu_ps(&x[i+8],yv[1]);
				_mm256_storeu_ps(&x[i+16],yv[2]);
				_mm256_storeu_ps(&x[i+24],yv[3]);
				_mm256_storeu_ps(&y[i+0],xv[0]);
				_mm256_storeu_ps(&y[i+8],xv[1]);
				_mm256_storeu_ps(&y[i+16],xv[2]);
				_mm256_storeu_ps(&y[i+24],xv[3]);
#endif

			   }

			   for(; (i+15) < n; i += 16) {
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                               xv[0] = _mm256_loadu_ps(&x[i+0]);
			       yv[0] = _mm256_loadu_ps(&y[i+0]);
			       _mm256_storeu_ps(&x[i+0],yv[0]);
			       _mm256_storeu_ps(&y[i+0],xv[0]);
			       xv[1] = _mm256_loadu_ps(&x[i+8]);
			       yv[1] = _mm256_loadu_ps(&y[i+8]);
			       _mm256_storeu_ps(&x[i+8],yv[1]);
			       _mm256_storeu_ps(&y[i+8],xv[1]); 
#else
                                xv[0] = _mm256_loadu_ps(&x[i+0]);
				xv[1] = _mm256_loadu_ps(&x[i+8]);
				yv[0] = _mm256_loadu_ps(&y[i+0]);
				yv[1] = _mm256_loadu_ps(&y[i+8]);
				_mm256_storeu_ps(&x[i+0],yv[0]);
				_mm256_storeu_ps(&x[i+8],yv[1]);
				_mm256_storeu_ps(&y[i+0],xv[0]);
				_mm256_storeu_ps(&y[i+8],xv[1]);
#endif

			   }

			   for(; (i+7) < n; i += 8) {
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                               xv[0] = _mm256_loadu_ps(&x[i+0]);
			       yv[0] = _mm256_loadu_ps(&y[i+0]);
			       _mm256_storeu_ps(&x[i+0],yv[0]);
			       _mm256_storeu_ps(&y[i+0],xv[0]);
#else
                                xv[0] = _mm256_loadu_ps(&x[i+0]);
				yv[0] = _mm256_loadu_ps(&y[i+0]);
				_mm256_storeu_ps(&x[i+0],yv[0]);
				_mm256_storeu_ps(&y[i+0],xv[0]);
				
#endif

			   }

			  for(; (i+0) < n; i += 1) {
                                const float tx = x[i]
				const float ty = y[i];
				y[i] = tx;
				x[i] = ty;
			  }

		       }
		        else {

			      for(i = 0; i != n; ++i) {
                                  const float tx = *x;
				  const float ty = *y;
				  *y = tx;
				  *x = ty;
				  y += incy;
				  x += incx;
			      }
			}
 
		 }


void
sswap_a_ymm8r4_unroll8x(const int32_t n,
		       float * __restrict __ATTR_ALIGN__(32) x,
		       const int32_t incx,
		       float * __restrict __ATTR_ALIGN__(32) y,
		       const int32_t incy) {
					  
                        if(__builtin_expect(0==n,0)) {return;}
			__ATTR_ALIGN__(32) __m256 xv[8];
			__ATTR_ALIGN__(32) __m256 yv[8];
			int32_t i;

			if(__builtin_expect(1==incx,1) &&
			   __builtin_expect(1==incy,1)) {
#if defined(__INTEL_COMPILER) || defined(__ICC)
                             __assume_aligned(x,32);
			     __assume_aligned(y,32);
#pragma code_align(32)
#elif defined(__GNUC__) && (!defined(__INTEL_COMPILER) || !defined(__ICC))
                             x = (float*)__builtin_assume_aligned(x,32);
			     y = (float*)__builtin_assume_aligned(y,32);
#endif
			   for(i = 0; (i+63) < n; i += 64) {
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                               _mm_prefetch((const char*)&x[i+16],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+16],_MM_HINT_T0);
                               xv[0] = _mm256_load_ps(&x[i+0]);
			       yv[0] = _mm256_load_ps(&y[i+0]);
			       _mm256_store_ps(&x[i+0],yv[0]);
			       _mm256_store_ps(&y[i+0],xv[0]);
			       xv[1] = _mm256_load_ps(&x[i+8]);
			       yv[1] = _mm256_load_ps(&y[i+8]);
			       _mm256_store_ps(&x[i+8],yv[1]);
			       _mm256_store_ps(&y[i+8],xv[1]);
			       _mm_prefetch((const char*)&x[i+32],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+32],_MM_HINT_T0);
			       xv[2] = _mm256_load_ps(&x[i+16]);
			       yv[2] = _mm256_load_ps(&y[i+16]);
			       _mm256_store_ps(&x[i+16],yv[2]);
			       _mm256_store_ps(&y[i+16],xv[2]);
			       xv[3] = _mm256_load_ps(&x[i+24]);
			       yv[3] = _mm256_load_ps(&y[i+24]);
			       _mm256_store_ps(&x[i+24],yv[3]);
			       _mm256_store_ps(&y[i+24],xv[3]);
			       _mm_prefetch((const char*)&x[i+48],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+48],_MM_HINT_T0);
			       xv[4] = _mm256_load_ps(&x[i+32]);
			       yv[4] = _mm256_load_ps(&y[i+32]);
			       _mm256_store_ps(&x[i+32],yv[4]);
			       _mm256_store_ps(&y[i+32],xv[4]);
			       xv[5] = _mm256_load_ps(&x[i+40]);
			       yv[5] = _mm256_load_ps(&y[i+40]);
			       _mm256_store_ps(&x[i+40],yv[5]);
			       _mm256_store_ps(&y[i+40],xv[5]);
			       _mm_prefetch((const char*)&x[i+64],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+64],_MM_HINT_T0);
			       xv[6] = _mm256_load_ps(&x[i+48]);
			       yv[6] = _mm256_load_ps(&y[i+48]);
			       _mm256_store_ps(&x[i+48],yv[6]);
			       _mm256_store_ps(&y[i+48],xv[6]);
			       xv[7] = _mm256_load_ps(&x[i+56]);
			       yv[7] = _mm256_load_ps(&y[i+56]);
			       _mm256_store_ps(&x[i+56],yv[7]);
			       _mm256_store_ps(&y[i+56],xv[7]);
			       
#else
                               _mm_prefetch((const char*)&x[i+16],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+16],_MM_HINT_T0);
			       _mm_prefetch((const char*)&x[i+32],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+32],_MM_HINT_T0);
			       _mm_prefetch((const char*)&x[i+48],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+48],_MM_HINT_T0);
			       _mm_prefetch((const char*)&x[i+64],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+64],_MM_HINT_T0);
			        xv[0] = _mm256_load_ps(&x[i+0]);
				xv[1] = _mm256_load_ps(&x[i+8]);
				xv[2] = _mm256_load_ps(&x[i+16]);
				xv[3] = _mm256_load_ps(&x[i+24]);
				xv[4] = _mm256_load_ps(&x[i+32]);
				xv[5] = _mm256_load_ps(&x[i+40]);
				xv[6] = _mm256_load_ps(&x[i+48]);
				xv[7] = _mm256_load_ps(&x[i+56]);
				yv[0] = _mm256_load_ps(&y[i+0]);
				yv[1] = _mm256_load_ps(&y[i+8]);
				yv[2] = _mm256_load_ps(&y[i+16]);
				yv[3] = _mm256_load_ps(&y[i+24]);
				yv[4] = _mm256_load_ps(&y[i+32]);
				yv[5] = _mm256_load_ps(&y[i+40]);
				yv[6] = _mm256_load_ps(&y[i+48]);
			        yv[7] = _mm256_load_ps(&y[i+56]);
				_mm256_store_ps(&x[i+0],yv[0]);
				_mm256_store_ps(&x[i+8],yv[1]);
				_mm256_store_ps(&x[i+16],yv[2]);
				_mm256_store_ps(&x[i+24],yv[3]);
				_mm256_store_ps(&x[i+32],yv[4]);
				_mm256_store_ps(&x[i+40],yv[5]);
				_mm256_store_ps(&x[i+48],yv[6]);
				_mm256_store_ps(&x[i+56],yv[7]);
				_mm256_store_ps(&y[i+0],xv[0]);
				_mm256_store_ps(&y[i+8],xv[1]);
				_mm256_store_ps(&y[i+16],xv[2]);
				_mm256_store_ps(&y[i+24],xv[3]);
				_mm256_store_ps(&y[i+32],xv[4]);
				_mm256_store_ps(&y[i+40],xv[5]);
				_mm256_store_ps(&y[i+48],xv[6]);
				_mm256_store_ps(&y[i+56],xv[7]);
				
				
#endif

			   }

			   for(; (i+31) < n; i += 32) {
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                               //_mm_prefetch((const char*)&x[i+16],_MM_HINT_T0);
			       //_mm_prefetch((const char*)&y[i+16],_MM_HINT_T0);
                               xv[0] = _mm256_load_ps(&x[i+0]);
			       yv[0] = _mm256_load_ps(&y[i+0]);
			       _mm256_store_ps(&x[i+0],yv[0]);
			       _mm256_store_ps(&y[i+0],xv[0]);
			       xv[1] = _mm256_load_ps(&x[i+8]);
			       yv[1] = _mm256_load_ps(&y[i+8]);
			       _mm256_store_ps(&x[i+8],yv[1]);
			       _mm256_store_ps(&y[i+8],xv[1]);
			       //_mm_prefetch((const char*)&x[i+32],_MM_HINT_T0);
			       //_mm_prefetch((const char*)&y[i+32],_MM_HINT_T0);
			       xv[2] = _mm256_load_ps(&x[i+16]);
			       yv[2] = _mm256_load_ps(&y[i+16]);
			       _mm256_store_ps(&x[i+16],yv[2]);
			       _mm256_store_ps(&y[i+16],xv[2]);
			       xv[3] = _mm256_load_ps(&x[i+24]);
			       yv[3] = _mm256_load_ps(&y[i+24]);
			       _mm256_store_ps(&x[i+24],yv[3]);
			       _mm256_store_ps(&y[i+24],xv[3]);
#else
                                xv[0] = _mm256_load_ps(&x[i+0]);
				xv[1] = _mm256_load_ps(&x[i+8]);
				xv[2] = _mm256_load_ps(&x[i+16]);
				xv[3] = _mm256_load_ps(&x[i+24]);
				yv[0] = _mm256_load_ps(&y[i+0]);
				yv[1] = _mm256_load_ps(&y[i+8]);
				yv[2] = _mm256_load_ps(&y[i+16]);
				yv[3] = _mm256_load_ps(&y[i+24]);
				_mm256_store_ps(&x[i+0],yv[0]);
				_mm256_store_ps(&x[i+8],yv[1]);
				_mm256_store_ps(&x[i+16],yv[2]);
				_mm256_store_ps(&x[i+24],yv[3]);
				_mm256_store_ps(&y[i+0],xv[0]);
				_mm256_store_ps(&y[i+8],xv[1]);
				_mm256_store_ps(&y[i+16],xv[2]);
				_mm256_store_ps(&y[i+24],xv[3]);
#endif

			   }

			   for(; (i+15) < n; i += 16) {
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                               xv[0] = _mm256_load_ps(&x[i+0]);
			       yv[0] = _mm256_load_ps(&y[i+0]);
			       _mm256_store_ps(&x[i+0],yv[0]);
			       _mm256_store_ps(&y[i+0],xv[0]);
			       xv[1] = _mm256_load_ps(&x[i+8]);
			       yv[1] = _mm256_load_ps(&y[i+8]);
			       _mm256_store_ps(&x[i+8],yv[1]);
			       _mm256_store_ps(&y[i+8],xv[1]); 
#else
                                xv[0] = _mm256_load_ps(&x[i+0]);
				xv[1] = _mm256_load_ps(&x[i+8]);
				yv[0] = _mm256_load_ps(&y[i+0]);
				yv[1] = _mm256_load_ps(&y[i+8]);
				_mm256_store_ps(&x[i+0],yv[0]);
				_mm256_store_ps(&x[i+8],yv[1]);
				_mm256_store_ps(&y[i+0],xv[0]);
				_mm256_store_ps(&y[i+8],xv[1]);
#endif

			   }

			   for(; (i+7) < n; i += 8) {
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                               xv[0] = _mm256_load_ps(&x[i+0]);
			       yv[0] = _mm256_load_ps(&y[i+0]);
			       _mm256_storeu_ps(&x[i+0],yv[0]);
			       _mm256_storeu_ps(&y[i+0],xv[0]);
#else
                                xv[0] = _mm256_load_ps(&x[i+0]);
				yv[0] = _mm256_load_ps(&y[i+0]);
				_mm256_store_ps(&x[i+0],yv[0]);
				_mm256_store_ps(&y[i+0],xv[0]);
				
#endif

			   }

			  for(; (i+0) < n; i += 1) {
                                const float tx = x[i]
				const float ty = y[i];
				y[i] = tx;
				x[i] = ty;
			  }

		       }
		        else {

			      for(i = 0; i != n; ++i) {
                                  const float tx = *x;
				  const float ty = *y;
				  *y = tx;
				  *x = ty;
				  y += incy;
				  x += incx;
			      }
			}
 
		 }


void
sswap_a_ymm8r4_unroll8x_omp(const int32_t n,
		            float * __restrict __ATTR_ALIGN__(32) x,
			    const int32_t incx,
			    float * __restrict __ATTR_ALIGN__(32) y,
			     const int32_t incy) {
					  
                        if(__builtin_expect(0==n,0)) {return;}
			__ATTR_ALIGN__(32) __m256 xv[8];
			__ATTR_ALIGN__(32) __m256 yv[8];
			int32_t i;
                        int32_t last_i;
			last_i = 0;
			if(__builtin_expect(1==incx,1) &&
			   __builtin_expect(1==incy,1)) {
#if defined(__INTEL_COMPILER) || defined(__ICC)
                             __assume_aligned(x,32);
			     __assume_aligned(y,32);
#pragma code_align(32)
#elif defined(__GNUC__) && (!defined(__INTEL_COMPILER) || !defined(__ICC))
                             x = (float*)__builtin_assume_aligned(x,32);
			     y = (float*)__builtin_assume_aligned(y,32);
#endif
#pragma omp parallel for schedule(static,64) default(none)  \
                           private(xv,yv,i) lastprivate(last_i) shared(n,x,y)
       			   for(i = 0; (i+63) < n; i += 64) {
			       last_i = i;
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                               _mm_prefetch((const char*)&x[i+16],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+16],_MM_HINT_T0);
                               xv[0] = _mm256_load_ps(&x[i+0]);
			       yv[0] = _mm256_load_ps(&y[i+0]);
			       _mm256_store_ps(&x[i+0],yv[0]);
			       _mm256_store_ps(&y[i+0],xv[0]);
			       xv[1] = _mm256_load_ps(&x[i+8]);
			       yv[1] = _mm256_load_ps(&y[i+8]);
			       _mm256_store_ps(&x[i+8],yv[1]);
			       _mm256_store_ps(&y[i+8],xv[1]);
			       _mm_prefetch((const char*)&x[i+32],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+32],_MM_HINT_T0);
			       xv[2] = _mm256_load_ps(&x[i+16]);
			       yv[2] = _mm256_load_ps(&y[i+16]);
			       _mm256_store_ps(&x[i+16],yv[2]);
			       _mm256_store_ps(&y[i+16],xv[2]);
			       xv[3] = _mm256_load_ps(&x[i+24]);
			       yv[3] = _mm256_load_ps(&y[i+24]);
			       _mm256_store_ps(&x[i+24],yv[3]);
			       _mm256_store_ps(&y[i+24],xv[3]);
			       _mm_prefetch((const char*)&x[i+48],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+48],_MM_HINT_T0);
			       xv[4] = _mm256_load_ps(&x[i+32]);
			       yv[4] = _mm256_load_ps(&y[i+32]);
			       _mm256_store_ps(&x[i+32],yv[4]);
			       _mm256_store_ps(&y[i+32],xv[4]);
			       xv[5] = _mm256_load_ps(&x[i+40]);
			       yv[5] = _mm256_load_ps(&y[i+40]);
			       _mm256_store_ps(&x[i+40],yv[5]);
			       _mm256_store_ps(&y[i+40],xv[5]);
			       _mm_prefetch((const char*)&x[i+64],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+64],_MM_HINT_T0);
			       xv[6] = _mm256_load_ps(&x[i+48]);
			       yv[6] = _mm256_load_ps(&y[i+48]);
			       _mm256_store_ps(&x[i+48],yv[6]);
			       _mm256_store_ps(&y[i+48],xv[6]);
			       xv[7] = _mm256_load_ps(&x[i+56]);
			       yv[7] = _mm256_load_ps(&y[i+56]);
			       _mm256_store_ps(&x[i+56],yv[7]);
			       _mm256_store_ps(&y[i+56],xv[7]);
			       
#else
                               _mm_prefetch((const char*)&x[i+16],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+16],_MM_HINT_T0);
			       _mm_prefetch((const char*)&x[i+32],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+32],_MM_HINT_T0);
			       _mm_prefetch((const char*)&x[i+48],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+48],_MM_HINT_T0);
			       _mm_prefetch((const char*)&x[i+64],_MM_HINT_T0);
			       _mm_prefetch((const char*)&y[i+64],_MM_HINT_T0);
			        xv[0] = _mm256_load_ps(&x[i+0]);
				xv[1] = _mm256_load_ps(&x[i+8]);
				xv[2] = _mm256_load_ps(&x[i+16]);
				xv[3] = _mm256_load_ps(&x[i+24]);
				xv[4] = _mm256_load_ps(&x[i+32]);
				xv[5] = _mm256_load_ps(&x[i+40]);
				xv[6] = _mm256_load_ps(&x[i+48]);
				xv[7] = _mm256_load_ps(&x[i+56]);
				yv[0] = _mm256_load_ps(&y[i+0]);
				yv[1] = _mm256_load_ps(&y[i+8]);
				yv[2] = _mm256_load_ps(&y[i+16]);
				yv[3] = _mm256_load_ps(&y[i+24]);
				yv[4] = _mm256_load_ps(&y[i+32]);
				yv[5] = _mm256_load_ps(&y[i+40]);
				yv[6] = _mm256_load_ps(&y[i+48]);
			        yv[7] = _mm256_load_ps(&y[i+56]);
				_mm256_store_ps(&x[i+0],yv[0]);
				_mm256_store_ps(&x[i+8],yv[1]);
				_mm256_store_ps(&x[i+16],yv[2]);
				_mm256_store_ps(&x[i+24],yv[3]);
				_mm256_store_ps(&x[i+32],yv[4]);
				_mm256_store_ps(&x[i+40],yv[5]);
				_mm256_store_ps(&x[i+48],yv[6]);
				_mm256_store_ps(&x[i+56],yv[7]);
				_mm256_store_ps(&y[i+0],xv[0]);
				_mm256_store_ps(&y[i+8],xv[1]);
				_mm256_store_ps(&y[i+16],xv[2]);
				_mm256_store_ps(&y[i+24],xv[3]);
				_mm256_store_ps(&y[i+32],xv[4]);
				_mm256_store_ps(&y[i+40],xv[5]);
				_mm256_store_ps(&y[i+48],xv[6]);
				_mm256_store_ps(&y[i+56],xv[7]);
				
				
#endif

			   }

			   for(; (last_i+31) < n; last_i += 32) {
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                               //_mm_prefetch((const char*)&x[i+16],_MM_HINT_T0);
			       //_mm_prefetch((const char*)&y[i+16],_MM_HINT_T0);
                               xv[0] = _mm256_load_ps(&x[last_i+0]);
			       yv[0] = _mm256_load_ps(&y[last_i+0]);
			       _mm256_store_ps(&x[last_i+0],yv[0]);
			       _mm256_store_ps(&y[last_i+0],xv[0]);
			       xv[1] = _mm256_load_ps(&x[last_i+8]);
			       yv[1] = _mm256_load_ps(&y[last_i+8]);
			       _mm256_store_ps(&x[last_i+8],yv[1]);
			       _mm256_store_ps(&y[last_i+8],xv[1]);
			       //_mm_prefetch((const char*)&x[i+32],_MM_HINT_T0);
			       //_mm_prefetch((const char*)&y[i+32],_MM_HINT_T0);
			       xv[2] = _mm256_load_ps(&x[last_i+16]);
			       yv[2] = _mm256_load_ps(&y[last_i+16]);
			       _mm256_store_ps(&x[last_i+16],yv[2]);
			       _mm256_store_ps(&y[last_i+16],xv[2]);
			       xv[3] = _mm256_load_ps(&x[last_i+24]);
			       yv[3] = _mm256_load_ps(&y[last_i+24]);
			       _mm256_store_ps(&x[last_i+24],yv[3]);
			       _mm256_store_ps(&y[last_i+24],xv[3]);
#else
                                xv[0] = _mm256_load_ps(&x[last_i+0]);
				xv[1] = _mm256_load_ps(&x[last_i+8]);
				xv[2] = _mm256_load_ps(&x[last_i+16]);
				xv[3] = _mm256_load_ps(&x[last_i+24]);
				yv[0] = _mm256_load_ps(&y[last_i+0]);
				yv[1] = _mm256_load_ps(&y[last_i+8]);
				yv[2] = _mm256_load_ps(&y[last_i+16]);
				yv[3] = _mm256_load_ps(&y[last_i+24]);
				_mm256_store_ps(&x[last_i+0],yv[0]);
				_mm256_store_ps(&x[last_i+8],yv[1]);
				_mm256_store_ps(&x[last_i+16],yv[2]);
				_mm256_store_ps(&x[last_i+24],yv[3]);
				_mm256_store_ps(&y[last_i+0],xv[0]);
				_mm256_store_ps(&y[last_i+8],xv[1]);
				_mm256_store_ps(&y[last_i+16],xv[2]);
				_mm256_store_ps(&y[last_i+24],xv[3]);
#endif

			   }

			   for(; (last_i+15) < n; last_i += 16) {
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                               xv[0] = _mm256_load_ps(&x[last_i+0]);
			       yv[0] = _mm256_load_ps(&y[last_i+0]);
			       _mm256_store_ps(&x[last_i+0],yv[0]);
			       _mm256_store_ps(&y[last_i+0],xv[0]);
			       xv[1] = _mm256_load_ps(&x[last_i+8]);
			       yv[1] = _mm256_load_ps(&y[last_i+8]);
			       _mm256_store_ps(&x[last_i+8],yv[1]);
			       _mm256_store_ps(&y[last_i+8],xv[1]); 
#else
                                xv[0] = _mm256_load_ps(&x[last_i+0]);
				xv[1] = _mm256_load_ps(&x[last_i+8]);
				yv[0] = _mm256_load_ps(&y[last_i+0]);
				yv[1] = _mm256_load_ps(&y[last_i+8]);
				_mm256_store_ps(&x[last_i+0],yv[0]);
				_mm256_store_ps(&x[last_i+8],yv[1]);
				_mm256_store_ps(&y[last_i+0],xv[0]);
				_mm256_store_ps(&y[last_i+8],xv[1]);
#endif

			   }

			   for(; (last_i+7) < n; last_i += 8) {
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                               xv[0] = _mm256_load_ps(&x[last_i+0]);
			       yv[0] = _mm256_load_ps(&y[last_i+0]);
			       _mm256_storeu_ps(&x[last_i+0],yv[0]);
			       _mm256_storeu_ps(&y[last_i+0],xv[0]);
#else
                                xv[0] = _mm256_load_ps(&x[last_i+0]);
				yv[0] = _mm256_load_ps(&y[last_i+0]);
				_mm256_store_ps(&x[last_i+0],yv[0]);
				_mm256_store_ps(&y[last_i+0],xv[0]);
				
#endif

			   }

			  for(; (last_i+0) < n; last_i += 1) {
                                const float tx = x[last_i]
				const float ty = y[last_i];
				y[last_i] = tx;
				x[last_i] = ty;
			  }

		       }
		        else {

			      for(i = 0; i != n; ++i) {
                                  const float tx = *x;
				  const float ty = *y;
				  *y = tx;
				  *x = ty;
				  y += incy;
				  x += incx;
			      }
			}
 
		 }



void
dswap_u_ymm4r8_unroll8x(const int32_t n,
		        double * __restrict x,
			const int32_t incx,
			double * __restrict y,
			const int32_t incy) {

			if(__builtin_expect(0==n,0)) {return;}

			__ATTR_ALIGN__(32) __m256d xv[8];
			__ATTR_ALIGN__(32) __m256d yv[8];
			int32_t i;

			if(__builtin_expect(1==incx,1) &&
			   __builtin_expect(1==incy,2)) {

                             for(i = 0; (i+31) < n; i += 32) {
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                                 _mm_prefetch((const char*)&x[i+8],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+8],_MM_HINT_T0);
				 xv[0] = _mm256_loadu_pd(&x[i+0]);
				 yv[0] = _mm256_loadu_pd(&y[i+0]);
				 _mm256_storeu_pd(&x[i+0],yv[0]);
				 _mm256_storeu_pd(&y[i+0],xv[0]);
				 xv[1] = _mm256_loadu_pd(&x[i+4]);
				 yv[1] = _mm256_loadu_pd(&y[i+4]);
				 _mm256_storeu_pd(&x[i+4],yv[1]);
				 _mm256_storeu_pd(&y[i+4],xv[1]);
				 _mm_prefetch((const char*)&x[i+16],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+16],_MM_HINT_T0);
				 xv[2] = _mm256_loadu_pd(&x[i+8]);
				 yv[2] = _mm256_loadu_pd(&y[i+8]);
				 _mm256_storeu_pd(&x[i+8],yv[2]);
				 _mm256_storeu_pd(&y[i+8],xv[2]);
				 xv[3] = _mm256_loadu_pd(&x[i+12]);
				 yv[3] = _mm256_loadu_pd(&y[i+12]);
				 _mm256_storeu_pd(&x[i+12],yv[3]);
				 _mm256_storeu_pd(&y[i+12],xv[3]);
				 _mm_prefetch((const char*)&x[i+24],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+24],_MM_HINT_T0);
				 xv[4] = _mm256_loadu_pd(&x[i+16]);
				 yv[4] = _mm256_loadu_pd(&y[i+16]);
				 _mm256_storeu_pd(&x[i+16],yv[4]);
				 _mm256_storeu_pd(&y[i+16],xv[4]);
				 xv[5] = _mm256_loadu_pd(&x[i+20]);
				 yv[5] = _mm256_loadu_pd(&y[i+20]);
				 _mm256_storeu_pd(&x[i+20],yv[5]);
				 _mm256_storeu_pd(&y[i+20],xv[5]);
				 _mm_prefetch((const char*)&x[i+32],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+32],_MM_HINT_T0);
				 xv[6] = _mm256_loadu_pd(&x[i+24]);
				 yv[6] = _mm256_loadu_pd(&y[i+24]);
				 _mm256_storeu_pd(&x[i+24],yv[6]);
				 _mm256_storeu_pd(&y[i+24],xv[6]);
				 xv[7] = _mm256_loadu_pd(&x[i+28]);
				 yv[7] = _mm256_loadu_pd(&y[i+28]);
				 _mm256_storeu_pd(&x[i+28],yv[7]);
				 _mm256_storeu_pd(&y[i+28],xv[7]);
				 
#else
                                 _mm_prefetch((const char*)&x[i+8],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+8],_MM_HINT_T0);
				 _mm_prefetch((const char*)&x[i+16],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+16],_MM_HINT_T0);
				 _mm_prefetch((const char*)&x[i+24],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+24],_MM_HINT_T0);
				 _mm_prefetch((const char*)&x[i+32],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+32],_MM_HINT_T0);
				 xv[0] = _mm256_loadu_pd(&x[i+0]);
				 xv[1] = _mm256_loadu_pd(&x[i+4]);
				 xv[2] = _mm256_loadu_pd(&x[i+8]);
				 xv[3] = _mm256_loadu_pd(&x[i+12]);
				 xv[4] = _mm256_loadu_pd(&x[i+16]);
				 xv[5] = _mm256_loadu_pd(&x[i+20]);
				 xv[6] = _mm256_loadu_pd(&x[i+24]);
				 xv[7] = _mm256_loadu_pd(&x[i+28]);
				 yv[0] = _mm256_loadu_pd(&y[i+0]);
				 yv[1] = _mm256_loadu_pd(&y[i+4]);
				 yv[2] = _mm256_loadu_pd(&y[i+8]);
				 yv[3] = _mm256_loadu_pd(&y[i+12]);
				 yv[4] = _mm256_loadu_pd(&y[i+16]);
				 yv[5] = _mm256_loadu_pd(&y[i+20]);
				 yv[6] = _mm256_loadu_pd(&y[i+24]);
				 yv[7] = _mm256_loadu_pd(&y[i+24]);
				 _mm256_storeu_pd(&x[i+0],yv[0]);
				 _mm256_storeu_pd(&x[i+4],yv[1]);
				 _mm256_storeu_pd(&x[i+8],yv[2]);
				 _mm256_storeu_pd(&x[i+12],yv[3]);
				 _mm256_storeu_pd(&x[i+16],yv[4]);
				 _mm256_storeu_pd(&x[i+20],yv[5]);
				 _mm256_storeu_pd(&x[i+24],yv[6]);
				 _mm256_storeu_pd(&x[i+28],yv[7]);
				 _mm256_storeu_pd(&y[i+0],xv[0]);
				 _mm256_storeu_pd(&y[i+4],xv[1]);
				 _mm256_storeu_pd(&y[i+8],xv[2]);
				 _mm256_storeu_pd(&y[i+12],xv[3]);
				 _mm256_storeu_pd(&y[i+16],xv[4]);
				 _mm256_storeu_pd(&y[i+20],xv[5]);
				 _mm256_storeu_pd(&y[i+24],xv[6]);
				 _mm256_storeu_pd(&y[i+28],xv[7]);
#endif

			     }

			     for(; (i+15) < n; i += 16) {
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                                 xv[0] = _mm256_loadu_pd(&x[i+0]);
				 yv[0] = _mm256_loadu_pd(&y[i+0]);
				 _mm256_storeu_pd(&x[i+0],yv[0]);
				 _mm256_storeu_pd(&y[i+0],xv[0]);
				 xv[1] = _mm256_loadu_pd(&x[i+4]);
				 yv[1] = _mm256_loadu_pd(&y[i+4]);
				 _mm256_storeu_pd(&x[i+4],yv[1]);
				 _mm256_storeu_pd(&y[i+4],xv[1]);
				 //_mm_prefetch((const char*)&x[i+16],_MM_HINT_T0);
				 //_mm_prefetch((const char*)&y[i+16],_MM_HINT_T0);
				 xv[2] = _mm256_loadu_pd(&x[i+8]);
				 yv[2] = _mm256_loadu_pd(&y[i+8]);
				 _mm256_storeu_pd(&x[i+8],yv[2]);
				 _mm256_storeu_pd(&y[i+8],xv[2]);
				 xv[3] = _mm256_loadu_pd(&x[i+12]);
				 yv[3] = _mm256_loadu_pd(&y[i+12]);
				 _mm256_storeu_pd(&x[i+12],yv[3]);
				 _mm256_storeu_pd(&y[i+12],xv[3]);
#else
                                 xv[0] = _mm256_loadu_pd(&x[i+0]);
				 xv[1] = _mm256_loadu_pd(&x[i+4]);
				 xv[2] = _mm256_loadu_pd(&x[i+8]);
				 xv[3] = _mm256_loadu_pd(&x[i+12]);
				 yv[0] = _mm256_loadu_pd(&y[i+0]);
				 yv[1] = _mm256_loadu_pd(&y[i+4]);
				 yv[2] = _mm256_loadu_pd(&y[i+8]);
				 yv[3] = _mm256_loadu_pd(&y[i+12]);
				 _mm256_storeu_pd(&x[i+0],yv[0]);
				 _mm256_storeu_pd(&x[i+4],yv[1]);
				 _mm256_storeu_pd(&x[i+8],yv[2]);
				 _mm256_storeu_pd(&x[i+12],yv[3]);
				 _mm256_storeu_pd(&y[i+0],xv[0]);
				 _mm256_storeu_pd(&y[i+4],xv[1]);
				 _mm256_storeu_pd(&y[i+8],xv[2]);
				 _mm256_storeu_pd(&y[i+12],xv[3]);
#endif

			     }

			     for(; (i+7) < n; i += 8) {
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                                 xv[0] = _mm256_loadu_pd(&x[i+0]);
				 yv[0] = _mm256_loadu_pd(&y[i+0]);
				 _mm256_storeu_pd(&x[i+0],yv[0]);
				 _mm256_storeu_pd(&y[i+0],xv[0]);
				 xv[1] = _mm256_loadu_pd(&x[i+4]);
				 yv[1] = _mm256_loadu_pd(&y[i+4]);
				 _mm256_storeu_pd(&x[i+4],yv[1]);
				 _mm256_storeu_pd(&y[i+4],xv[1]); 
#else
                                 xv[0] = _mm256_loadu_pd(&x[i+0]);
				 xv[1] = _mm256_loadu_pd(&x[i+4]);
				 yv[0] = _mm256_loadu_pd(&y[i+0]);
				 yv[1] = _mm256_loadu_pd(&y[i+4])
				 _mm256_storeu_pd(&x[i+0],yv[0]);
				 _mm256_storeu_pd(&x[i+4],yv[1]);
				 _mm256_storeu_pd(&y[i+0],xv[0]);
				 _mm256_storeu_pd(&y[i+4],xv[1]);
#endif
			     }

			     for(; (i+3) < n; i += 4) {
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                                 xv[0] = _mm256_loadu_pd(&x[i+0]);
				 yv[0] = _mm256_loadu_pd(&y[i+0]);
				 _mm256_storeu_pd(&x[i+0],yv[0]);
				 _mm256_storeu_pd(&y[i+0],xv[0]);
#else
                                 xv[0] = _mm256_loadu_pd(&x[i+0]);
				 yv[0] = _mm256_loadu_pd(&y[i+0]);
				 _mm256_storeu_pd(&x[i+0],yv[0]);
				 _mm256_storeu_pd(&y[i+0],xv[0]); 
#endif
			     }

			     for(; (i+0) < n; i += 1) {
                                    const double tx = x[i]
				    const double ty = y[i];
				    y[i] = tx;
				    x[i] = ty;
			     }
			}
			else {
                               for(i = 0; i != n; ++i) {
                                  const double tx = *x;
				  const double ty = *y;
				  *y = tx;
				  *x = ty;
				  y += incy;
				  x += incx;
			      }
			}

		  }



void
dswap_a_ymm4r8_unroll8x(const int32_t n,
		        double * __restrict __ATTR_ALIGN__(32) x,
			const int32_t incx,
			double * __restrict __ATTR_ALIGN__(32) y,
			const int32_t incy) {

			if(__builtin_expect(0==n,0)) {return;}

			__ATTR_ALIGN__(32) __m256d xv[8];
			__ATTR_ALIGN__(32) __m256d yv[8];
			int32_t i;

			if(__builtin_expect(1==incx,1) &&
			   __builtin_expect(1==incy,2)) {
#if defined(__INTEL_COMPILER) || defined(__ICC)
                             __assume_aligned(x,32);
			     __assume_aligned(y,32);
#pragma code_align(32)
#elif defined(__GNUC__) && (!defined(__INTEL_COMPILER) || !defined(__ICC))
                             x = (double*)__builtin_assume_aligned(x,32);
			     y = (double*)__builtin_assume_aligned(y,32);
#endif
                             for(i = 0; (i+31) < n; i += 32) {
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                                 _mm_prefetch((const char*)&x[i+8],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+8],_MM_HINT_T0);
				 xv[0] = _mm256_load_pd(&x[i+0]);
				 yv[0] = _mm256_load_pd(&y[i+0]);
				 _mm256_store_pd(&x[i+0],yv[0]);
				 _mm256_store_pd(&y[i+0],xv[0]);
				 xv[1] = _mm256_load_pd(&x[i+4]);
				 yv[1] = _mm256_load_pd(&y[i+4]);
				 _mm256_store_pd(&x[i+4],yv[1]);
				 _mm256_store_pd(&y[i+4],xv[1]);
				 _mm_prefetch((const char*)&x[i+16],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+16],_MM_HINT_T0);
				 xv[2] = _mm256_load_pd(&x[i+8]);
				 yv[2] = _mm256_load_pd(&y[i+8]);
				 _mm256_store_pd(&x[i+8],yv[2]);
				 _mm256_store_pd(&y[i+8],xv[2]);
				 xv[3] = _mm256_load_pd(&x[i+12]);
				 yv[3] = _mm256_load_pd(&y[i+12]);
				 _mm256_store_pd(&x[i+12],yv[3]);
				 _mm256_store_pd(&y[i+12],xv[3]);
				 _mm_prefetch((const char*)&x[i+24],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+24],_MM_HINT_T0);
				 xv[4] = _mm256_load_pd(&x[i+16]);
				 yv[4] = _mm256_load_pd(&y[i+16]);
				 _mm256_store_pd(&x[i+16],yv[4]);
				 _mm256_store_pd(&y[i+16],xv[4]);
				 xv[5] = _mm256_load_pd(&x[i+20]);
				 yv[5] = _mm256_load_pd(&y[i+20]);
				 _mm256_storeu_pd(&x[i+20],yv[5]);
				 _mm256_storeu_pd(&y[i+20],xv[5]);
				 _mm_prefetch((const char*)&x[i+32],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+32],_MM_HINT_T0);
				 xv[6] = _mm256_load_pd(&x[i+24]);
				 yv[6] = _mm256_load_pd(&y[i+24]);
				 _mm256_store_pd(&x[i+24],yv[6]);
				 _mm256_store_pd(&y[i+24],xv[6]);
				 xv[7] = _mm256_load_pd(&x[i+28]);
				 yv[7] = _mm256_load_pd(&y[i+28]);
				 _mm256_store_pd(&x[i+28],yv[7]);
				 _mm256_store_pd(&y[i+28],xv[7]);
				 
#else
                                 _mm_prefetch((const char*)&x[i+8],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+8],_MM_HINT_T0);
				 _mm_prefetch((const char*)&x[i+16],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+16],_MM_HINT_T0);
				 _mm_prefetch((const char*)&x[i+24],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+24],_MM_HINT_T0);
				 _mm_prefetch((const char*)&x[i+32],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+32],_MM_HINT_T0);
				 xv[0] = _mm256_load_pd(&x[i+0]);
				 xv[1] = _mm256_load_pd(&x[i+4]);
				 xv[2] = _mm256_load_pd(&x[i+8]);
				 xv[3] = _mm256_load_pd(&x[i+12]);
				 xv[4] = _mm256_load_pd(&x[i+16]);
				 xv[5] = _mm256_load_pd(&x[i+20]);
				 xv[6] = _mm256_load_pd(&x[i+24]);
				 xv[7] = _mm256_load_pd(&x[i+28]);
				 yv[0] = _mm256_load_pd(&y[i+0]);
				 yv[1] = _mm256_load_pd(&y[i+4]);
				 yv[2] = _mm256_load_pd(&y[i+8]);
				 yv[3] = _mm256_load_pd(&y[i+12]);
				 yv[4] = _mm256_load_pd(&y[i+16]);
				 yv[5] = _mm256_load_pd(&y[i+20]);
				 yv[6] = _mm256_load_pd(&y[i+24]);
				 yv[7] = _mm256_load_pd(&y[i+24]);
				 _mm256_store_pd(&x[i+0],yv[0]);
				 _mm256_store_pd(&x[i+4],yv[1]);
				 _mm256_store_pd(&x[i+8],yv[2]);
				 _mm256_store_pd(&x[i+12],yv[3]);
				 _mm256_store_pd(&x[i+16],yv[4]);
				 _mm256_store_pd(&x[i+20],yv[5]);
				 _mm256_store_pd(&x[i+24],yv[6]);
				 _mm256_store_pd(&x[i+28],yv[7]);
				 _mm256_store_pd(&y[i+0],xv[0]);
				 _mm256_store_pd(&y[i+4],xv[1]);
				 _mm256_store_pd(&y[i+8],xv[2]);
				 _mm256_store_pd(&y[i+12],xv[3]);
				 _mm256_store_pd(&y[i+16],xv[4]);
				 _mm256_store_pd(&y[i+20],xv[5]);
				 _mm256_store_pd(&y[i+24],xv[6]);
				 _mm256_store_pd(&y[i+28],xv[7]);
#endif

			     }

			     for(; (i+15) < n; i += 16) {
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                                 xv[0] = _mm256_load_pd(&x[i+0]);
				 yv[0] = _mm256_load_pd(&y[i+0]);
				 _mm256_store_pd(&x[i+0],yv[0]);
				 _mm256_store_pd(&y[i+0],xv[0]);
				 xv[1] = _mm256_load_pd(&x[i+4]);
				 yv[1] = _mm256_load_pd(&y[i+4]);
				 _mm256_store_pd(&x[i+4],yv[1]);
				 _mm256_store_pd(&y[i+4],xv[1]);
				 //_mm_prefetch((const char*)&x[i+16],_MM_HINT_T0);
				 //_mm_prefetch((const char*)&y[i+16],_MM_HINT_T0);
				 xv[2] = _mm256_load_pd(&x[i+8]);
				 yv[2] = _mm256_load_pd(&y[i+8]);
				 _mm256_store_pd(&x[i+8],yv[2]);
				 _mm256_store_pd(&y[i+8],xv[2]);
				 xv[3] = _mm256_load_pd(&x[i+12]);
				 yv[3] = _mm256_load_pd(&y[i+12]);
				 _mm256_store_pd(&x[i+12],yv[3]);
				 _mm256_store_pd(&y[i+12],xv[3]);
#else
                                 xv[0] = _mm256_load_pd(&x[i+0]);
				 xv[1] = _mm256_load_pd(&x[i+4]);
				 xv[2] = _mm256_load_pd(&x[i+8]);
				 xv[3] = _mm256_load_pd(&x[i+12]);
				 yv[0] = _mm256_load_pd(&y[i+0]);
				 yv[1] = _mm256_load_pd(&y[i+4]);
				 yv[2] = _mm256_load_pd(&y[i+8]);
				 yv[3] = _mm256_load_pd(&y[i+12]);
				 _mm256_store_pd(&x[i+0],yv[0]);
				 _mm256_store_pd(&x[i+4],yv[1]);
				 _mm256_store_pd(&x[i+8],yv[2]);
				 _mm256_store_pd(&x[i+12],yv[3]);
				 _mm256_store_pd(&y[i+0],xv[0]);
				 _mm256_store_pd(&y[i+4],xv[1]);
				 _mm256_store_pd(&y[i+8],xv[2]);
				 _mm256_store_pd(&y[i+12],xv[3]);
#endif

			     }

			     for(; (i+7) < n; i += 8) {
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                                 xv[0] = _mm256_load_pd(&x[i+0]);
				 yv[0] = _mm256_load_pd(&y[i+0]);
				 _mm256_store_pd(&x[i+0],yv[0]);
				 _mm256_store_pd(&y[i+0],xv[0]);
				 xv[1] = _mm256_load_pd(&x[i+4]);
				 yv[1] = _mm256_load_pd(&y[i+4]);
				 _mm256_store_pd(&x[i+4],yv[1]);
				 _mm256_store_pd(&y[i+4],xv[1]); 
#else
                                 xv[0] = _mm256_load_pd(&x[i+0]);
				 xv[1] = _mm256_load_pd(&x[i+4]);
				 yv[0] = _mm256_load_pd(&y[i+0]);
				 yv[1] = _mm256_load_pd(&y[i+4])
				 _mm256_store_pd(&x[i+0],yv[0]);
				 _mm256_store_pd(&x[i+4],yv[1]);
				 _mm256_store_pd(&y[i+0],xv[0]);
				 _mm256_store_pd(&y[i+4],xv[1]);
#endif
			     }

			     for(; (i+3) < n; i += 4) {
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                                 xv[0] = _mm256_load_pd(&x[i+0]);
				 yv[0] = _mm256_load_pd(&y[i+0]);
				 _mm256_store_pd(&x[i+0],yv[0]);
				 _mm256_store_pd(&y[i+0],xv[0]);
#else
                                 xv[0] = _mm256_load_pd(&x[i+0]);
				 yv[0] = _mm256_load_pd(&y[i+0]);
				 _mm256_store_pd(&x[i+0],yv[0]);
				 _mm256_store_pd(&y[i+0],xv[0]); 
#endif
			     }

			     for(; (i+0) < n; i += 1) {
                                    const double tx = x[i]
				    const double ty = y[i];
				    y[i] = tx;
				    x[i] = ty;
			     }
			}
			else {
                               for(i = 0; i != n; ++i) {
                                  const double tx = *x;
				  const double ty = *y;
				  *y = tx;
				  *x = ty;
				  y += incy;
				  x += incx;
			      }
			}

		  }


void
dswap_a_ymm4r8_unroll8x_omp(const int32_t n,
		            double * __restrict __ATTR_ALIGN__(32) x,
			    const int32_t incx,
			    double * __restrict __ATTR_ALIGN__(32) y,
			    const int32_t incy) {

			if(__builtin_expect(0==n,0)) {return;}

			__ATTR_ALIGN__(32) __m256d xv[8];
			__ATTR_ALIGN__(32) __m256d yv[8];
			int32_t i;
                        int32_t last_i;
			last_i = 0;
			if(__builtin_expect(1==incx,1) &&
			   __builtin_expect(1==incy,2)) {
#if defined(__INTEL_COMPILER) || defined(__ICC)
                             __assume_aligned(x,32);
			     __assume_aligned(y,32);
#pragma code_align(32)
#elif defined(__GNUC__) && (!defined(__INTEL_COMPILER) || !defined(__ICC))
                             x = (double*)__builtin_assume_aligned(x,32);
			     y = (double*)__builtin_assume_aligned(y,32);
#endif
#pragma omp parallel for schedule(static,32) default(none)  \
                           private(xv,yv,i) lastprivate(last_i) shared(n,x,y)
                             for(i = 0; (i+31) < n; i += 32) {
			         last_i = i;
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                                 _mm_prefetch((const char*)&x[i+8],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+8],_MM_HINT_T0);
				 xv[0] = _mm256_load_pd(&x[i+0]);
				 yv[0] = _mm256_load_pd(&y[i+0]);
				 _mm256_store_pd(&x[i+0],yv[0]);
				 _mm256_store_pd(&y[i+0],xv[0]);
				 xv[1] = _mm256_load_pd(&x[i+4]);
				 yv[1] = _mm256_load_pd(&y[i+4]);
				 _mm256_store_pd(&x[i+4],yv[1]);
				 _mm256_store_pd(&y[i+4],xv[1]);
				 _mm_prefetch((const char*)&x[i+16],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+16],_MM_HINT_T0);
				 xv[2] = _mm256_load_pd(&x[i+8]);
				 yv[2] = _mm256_load_pd(&y[i+8]);
				 _mm256_store_pd(&x[i+8],yv[2]);
				 _mm256_store_pd(&y[i+8],xv[2]);
				 xv[3] = _mm256_load_pd(&x[i+12]);
				 yv[3] = _mm256_load_pd(&y[i+12]);
				 _mm256_store_pd(&x[i+12],yv[3]);
				 _mm256_store_pd(&y[i+12],xv[3]);
				 _mm_prefetch((const char*)&x[i+24],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+24],_MM_HINT_T0);
				 xv[4] = _mm256_load_pd(&x[i+16]);
				 yv[4] = _mm256_load_pd(&y[i+16]);
				 _mm256_store_pd(&x[i+16],yv[4]);
				 _mm256_store_pd(&y[i+16],xv[4]);
				 xv[5] = _mm256_load_pd(&x[i+20]);
				 yv[5] = _mm256_load_pd(&y[i+20]);
				 _mm256_storeu_pd(&x[i+20],yv[5]);
				 _mm256_storeu_pd(&y[i+20],xv[5]);
				 _mm_prefetch((const char*)&x[i+32],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+32],_MM_HINT_T0);
				 xv[6] = _mm256_load_pd(&x[i+24]);
				 yv[6] = _mm256_load_pd(&y[i+24]);
				 _mm256_store_pd(&x[i+24],yv[6]);
				 _mm256_store_pd(&y[i+24],xv[6]);
				 xv[7] = _mm256_load_pd(&x[i+28]);
				 yv[7] = _mm256_load_pd(&y[i+28]);
				 _mm256_store_pd(&x[i+28],yv[7]);
				 _mm256_store_pd(&y[i+28],xv[7]);
				 
#else
                                 _mm_prefetch((const char*)&x[i+8],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+8],_MM_HINT_T0);
				 _mm_prefetch((const char*)&x[i+16],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+16],_MM_HINT_T0);
				 _mm_prefetch((const char*)&x[i+24],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+24],_MM_HINT_T0);
				 _mm_prefetch((const char*)&x[i+32],_MM_HINT_T0);
				 _mm_prefetch((const char*)&y[i+32],_MM_HINT_T0);
				 xv[0] = _mm256_load_pd(&x[i+0]);
				 xv[1] = _mm256_load_pd(&x[i+4]);
				 xv[2] = _mm256_load_pd(&x[i+8]);
				 xv[3] = _mm256_load_pd(&x[i+12]);
				 xv[4] = _mm256_load_pd(&x[i+16]);
				 xv[5] = _mm256_load_pd(&x[i+20]);
				 xv[6] = _mm256_load_pd(&x[i+24]);
				 xv[7] = _mm256_load_pd(&x[i+28]);
				 yv[0] = _mm256_load_pd(&y[i+0]);
				 yv[1] = _mm256_load_pd(&y[i+4]);
				 yv[2] = _mm256_load_pd(&y[i+8]);
				 yv[3] = _mm256_load_pd(&y[i+12]);
				 yv[4] = _mm256_load_pd(&y[i+16]);
				 yv[5] = _mm256_load_pd(&y[i+20]);
				 yv[6] = _mm256_load_pd(&y[i+24]);
				 yv[7] = _mm256_load_pd(&y[i+24]);
				 _mm256_store_pd(&x[i+0],yv[0]);
				 _mm256_store_pd(&x[i+4],yv[1]);
				 _mm256_store_pd(&x[i+8],yv[2]);
				 _mm256_store_pd(&x[i+12],yv[3]);
				 _mm256_store_pd(&x[i+16],yv[4]);
				 _mm256_store_pd(&x[i+20],yv[5]);
				 _mm256_store_pd(&x[i+24],yv[6]);
				 _mm256_store_pd(&x[i+28],yv[7]);
				 _mm256_store_pd(&y[i+0],xv[0]);
				 _mm256_store_pd(&y[i+4],xv[1]);
				 _mm256_store_pd(&y[i+8],xv[2]);
				 _mm256_store_pd(&y[i+12],xv[3]);
				 _mm256_store_pd(&y[i+16],xv[4]);
				 _mm256_store_pd(&y[i+20],xv[5]);
				 _mm256_store_pd(&y[i+24],xv[6]);
				 _mm256_store_pd(&y[i+28],xv[7]);
#endif

			     }

			     for(; (last_i+15) < n; last_i += 16) {
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                                 xv[0] = _mm256_load_pd(&x[last_i+0]);
				 yv[0] = _mm256_load_pd(&y[last_i+0]);
				 _mm256_store_pd(&x[last_i+0],yv[0]);
				 _mm256_store_pd(&y[last_i+0],xv[0]);
				 xv[1] = _mm256_load_pd(&x[last_i+4]);
				 yv[1] = _mm256_load_pd(&y[last_i+4]);
				 _mm256_store_pd(&x[last_i+4],yv[1]);
				 _mm256_store_pd(&y[last_i+4],xv[1]);
				 //_mm_prefetch((const char*)&x[i+16],_MM_HINT_T0);
				 //_mm_prefetch((const char*)&y[i+16],_MM_HINT_T0);
				 xv[2] = _mm256_load_pd(&x[last_i+8]);
				 yv[2] = _mm256_load_pd(&y[last_i+8]);
				 _mm256_store_pd(&x[last_i+8],yv[2]);
				 _mm256_store_pd(&y[last_i+8],xv[2]);
				 xv[3] = _mm256_load_pd(&x[last_i+12]);
				 yv[3] = _mm256_load_pd(&y[last_i+12]);
				 _mm256_store_pd(&x[last_i+12],yv[3]);
				 _mm256_store_pd(&y[last_i+12],xv[3]);
#else
                                 xv[0] = _mm256_load_pd(&x[last_i+0]);
				 xv[1] = _mm256_load_pd(&x[last_i+4]);
				 xv[2] = _mm256_load_pd(&x[last_i+8]);
				 xv[3] = _mm256_load_pd(&x[last_i+12]);
				 yv[0] = _mm256_load_pd(&y[last_i+0]);
				 yv[1] = _mm256_load_pd(&y[last_i+4]);
				 yv[2] = _mm256_load_pd(&y[last_i+8]);
				 yv[3] = _mm256_load_pd(&y[last_i+12]);
				 _mm256_store_pd(&x[last_i+0],yv[0]);
				 _mm256_store_pd(&x[last_i+4],yv[1]);
				 _mm256_store_pd(&x[last_i+8],yv[2]);
				 _mm256_store_pd(&x[last_i+12],yv[3]);
				 _mm256_store_pd(&y[last_i+0],xv[0]);
				 _mm256_store_pd(&y[last_i+4],xv[1]);
				 _mm256_store_pd(&y[last_i+8],xv[2]);
				 _mm256_store_pd(&y[last_i+12],xv[3]);
#endif

			     }

			     for(; (last_i+7) < n; last_i += 8) {
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                                 xv[0] = _mm256_load_pd(&x[last_i+0]);
				 yv[0] = _mm256_load_pd(&y[last_i+0]);
				 _mm256_store_pd(&x[last_i+0],yv[0]);
				 _mm256_store_pd(&y[last_i+0],xv[0]);
				 xv[1] = _mm256_load_pd(&x[last_i+4]);
				 yv[1] = _mm256_load_pd(&y[last_i+4]);
				 _mm256_store_pd(&x[last_i+4],yv[1]);
				 _mm256_store_pd(&y[last_i+4],xv[1]); 
#else
                                 xv[0] = _mm256_load_pd(&x[last_i+0]);
				 xv[1] = _mm256_load_pd(&x[last_i+4]);
				 yv[0] = _mm256_load_pd(&y[last_i+0]);
				 yv[1] = _mm256_load_pd(&y[last_i+4])
				 _mm256_store_pd(&x[last_i+0],yv[0]);
				 _mm256_store_pd(&x[last_i+4],yv[1]);
				 _mm256_store_pd(&y[last_i+0],xv[0]);
				 _mm256_store_pd(&y[last_i+4],xv[1]);
#endif
			     }

			     for(; (i+3) < n; i += 4) {
#if (GMS_INTERLEAVE_SIMD_OPS_SCHEDULE) == 1
                                 xv[0] = _mm256_load_pd(&x[last_i+0]);
				 yv[0] = _mm256_load_pd(&y[last_i+0]);
				 _mm256_store_pd(&x[last_i+0],yv[0]);
				 _mm256_store_pd(&y[last_i+0],xv[0]);
#else
                                 xv[0] = _mm256_load_pd(&x[last_i+0]);
				 yv[0] = _mm256_load_pd(&y[last_i+0]);
				 _mm256_store_pd(&x[last_i+0],yv[0]);
				 _mm256_store_pd(&y[last_i+0],xv[0]); 
#endif
			     }

			     for(; (last_i+0) < n; last_i += 1) {
                                    const double tx = x[last_i]
				    const double ty = y[last_i];
				    y[last_i] = tx;
				    x[last_i] = ty;
			     }
			}
			else {
                               for(i = 0; i != n; ++i) {
                                  const double tx = *x;
				  const double ty = *y;
				  *y = tx;
				  *x = ty;
				  y += incy;
				  x += incx;
			      }
			}

		  }
		 





