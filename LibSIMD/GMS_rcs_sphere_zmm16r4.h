


#ifndef __GMS_RCS_SPHERE_ZMM16R4_H__
#define __GMS_RCS_SPHERE_ZMM16R4_H__ 040120231245



/*MIT License
Copyright (c) 2020 Bernard Gingold
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/



    const unsigned int GMS_RCS_SPHERE_ZMM16R4_MAJOR = 1U;
    const unsigned int GMS_RCS_SPHERE_ZMM16R4_MINOR = 0U;
    const unsigned int GMS_RCS_SPHERE_ZMM16R4_MICRO = 0U;
    const unsigned int GMS_RCS_SPHERE_ZMM16R4_FULLVER =
      1000U*GMS_RCS_SPHERE_ZMM16R4_MAJOR+
      100U*GMS_RCS_SPHERE_ZMM16R4_MINOR+
      10U*GMS_RCS_SPHERE_ZMM16R4_MICRO;
    const char * const GMS_RCS_SPHERE_ZMM16R4_CREATION_DATE = "04-01-2023 12:45 AM +00200 (WED 04 JAN 2023 GMT+2)";
    const char * const GMS_RCS_SPHERE_ZMM16R4_BUILD_DATE    = __DATE__ ":" __TIME__;
    const char * const GMS_RCS_SPHERE_ZMM16R4_AUTHOR        = "Programmer: Bernard Gingold, contact: beniekg@gmail.com";
    const char * const GMS_RCS_SPHERE_ZMM16R4_DESCRIPTION   = "AVX512 optimized Sphere Radar Cross Section (analytic) functionality."


#include <immintrin.h>




              /*
                       Radar Cross Section Handbook 1, page 147, formula 3.2-4
                       Backscattering function ,resonance region 0.4 .le. k0a .le. 20.0
                       Theta = 0, far-field
                       Valid for k0a < 1 only!!
                   */


                     void Fth_f324_zmm16r4(   const __m512 k0a, // size of sphere expressed in wavenumber units
                                               __m512 * __restrict F0r, // the results
                                               __m512 * __restrict F0i)
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                     void Fth_f324_zmm16r4_a(  const float * __restrict __attribute__((aligned(64))) pk0a, // size of sphere expressed in wavenumber units
                                               __m512 * __restrict F0r, // the results
                                               __m512 * __restrict F0i)
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                     void Fth_f324_zmm16r4_u(  const float * __restrict  pk0a, // size of sphere expressed in wavenumber units
                                               __m512 * __restrict F0r, // the results
                                               __m512 * __restrict F0i) 
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));



        //////////////////////////////////////////////////////////////////////////////////////////////


                      /*
                        Radar Cross Section Handbook 1, page 147, formula 3.2-5
                        Backscattering cross section
                        
                    */


                    __m512 rcs_f325_zmm16r4(const __m512 k0,
                                            const __m512 a ) 
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                   __m512 rcs_f325_zmm16r4_a(const float * __restrict __attribute__((aligned(64))) pk0,
                                             const float * __restrict __attribute__((aligned(64))) pa )
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                   __m512 rcs_f325_zmm16r4_u(const float * __restrict pk0,
                                             const float * __restrict pa )
                                                          __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                /*
                        Creeping wave term, F c(0) at the upper end of the resonance region.
                        Formula 3.2-8
                    */

          /////////////////////////////////////////////////////////////////////////////////////////////


                   void Fc_f328_zmm16r4( const __m512 x,//k0a
                                         __m512 * __restrict Fc0r,
                                         __m512 * __restrict Fc0i)
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                  void Fc_f328_zmm16r4_a( const float * __restrict __attribute__((aligned(64))) px,//k0a
                                           float * __restrict __attribute__((aligned(64))) Fc0r,
                                           float * __restrict __attribute__((aligned(64))) Fc0i) 
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                   void Fc_f328_zmm16r4_u(const float * __restrict px,//k0a
                                           float * __restrict  Fc0r,
                                           float * __restrict  Fc0i) 
                                                          __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                  /*
                       The complex scattering amplitudes near the lower end of the resonance
                       region (say, 0.4 < k^a < 1) 
                       E-plane approximation
                       These equations are not valid at all for k0a > 1. They are
                       valid for all theta angles.
                   */


             ///////////////////////////////////////////////////////////////////////////////////////


                    void S1_f3213_zmm16r4( const __m512 k0a,
                                            const __m512 tht,
                                           __m512 * __restrict S1r,
                                           __m512 * __restrict S1i)    
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));

                    void S1_f3213_zmm16r4_a( const float * __restrict __attribute__((aligned(64))) pk0a,
                                              const float * __restrict __attribute__((aligned(64))) ptht,
                                              float * __restrict __attribute__((aligned(64))) S1r,
                                              float * __restrict __attribute__((aligned(64))) S1i)
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                     void S1_f3213_zmm16r4_u( const float * __restrict  pk0a,
                                               const float * __restrict  ptht,
                                               float * __restrict S1r,
                                               float * __restrict S1i)        
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                       /*
                       The complex scattering amplitudes near the lower end of the resonance
                       region (say, 0.4 < k^a < 1) 
                       H-plane approximation
                       These equations are not valid at all for k0a > 1. They are
                       valid for all theta angles.
                   */


              //////////////////////////////////////////////////////////////////////////////////////////


                     void S2_f3214_zmm16r4( const __m512 k0a,
                                             const __m512 tht,
                                             __m512 * __restrict S2r,
                                             __m512 * __restrict S2i)
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                     void S2_f3214_zmm16r4_a( const float * __restrict __attribute__((aligned(64))) pk0a,
                                               const float * __restrict __attribute__((aligned(64))) ptht,
                                               float * __restrict __attribute__((aligned(64))) S2r,
                                               float * __restrict __attribute__((aligned(64))) S2i)
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                     void S2_f3214_zmm16r4_u( const float * __restrict  pk0a,
                                               const float * __restrict  ptht,
                                               float * __restrict  S2r,
                                               float * __restrict  S2i) 
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                 /*
                       Formula 3.2-16, optics contribution at upper end of resonance region
                   */


            //////////////////////////////////////////////////////////////////////////////////////////////


                    void S1_f3216_zmm16r4(const __m512 k0a,
                                          const __m512 tht,
                                          __m512 * __restrict S1r,
                                          __m512 * __restrict S1i)    
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                    void S1_f3216_zmm16r4_a(const float * __restrict __attribute__((aligned(64))) pk0a,
                                            const float * __restrict __attribute__((aligned(64))) ptht,
                                            float * __restrict __attribute__((aligned(64))) S1r,
                                            float * __restrict __attribute__((aligned(64))) S1i)
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                    void S1_f3216_zmm16r4_u(const float * __restrict  pk0a,
                                            const float * __restrict  ptht,
                                            float * __restrict  S1r,
                                            float * __restrict  S1i)
                                                          __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                      /*
                       Formula 3.2-17, optics contribution at upper end of resonance region
                   */


           /////////////////////////////////////////////////////////////////////////////////////////////////


                     void S2_f3217_zmm16r4(const __m512 k0a,
                                           const __m512 tht,
                                           __m512 * __restrict S2r,
                                           __m512 * __restrict S2i)
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                     void S2_f3217_zmm16r4_a(const float * __restrict __attribute__((aligned(64)))  pk0a,
                                             const float * __restrict __attribute__((aligned(64)))  ptht,
                                             float * __restrict __attribute__((aligned(64)))  S2r,
                                             float * __restrict __attribute__((aligned(64)))  S2i)
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                     void S2_f3217_zmm16r4_u(const float * __restrict  pk0a,
                                             const float * __restrict  ptht,
                                             float * __restrict  S2r,
                                             float * __restrict  S2i)
                                                           __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                      /*
                        Low frequency region (k0a < 0.4) i.e. Rayleigh-region complex scattering
                        amplitudes.
                        Formula 3.2-20
                    */

                 //////////////////////////////////////////////////////////////////////////////////////


                      __m512 S1_f3220_zmm16r4(const __m512 k0a,
                                              const __m512 tht) 
                                                          __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                      void S1_f3220_zmm16r4_a(const float * __restrict __attribute__((aligned(64)))  pk0a,
                                              const float * __restrict __attribute__((aligned(64)))  ptht,
                                              float * __restrict __attribute__((aligned(64)))  S1)
                                                          __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                       void S1_f3220_zmm16r4_u(const float * __restrict pk0a,
                                               const float * __restrict ptht,
                                               float * __restrict S1)
                                                          __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                         /*
                        Low frequency region (k0a < 0.4) i.e. Rayleigh-region complex scattering
                        amplitudes.
                        Formula 3.2-21
                    */


             ///////////////////////////////////////////////////////////////////////////////////////


                        __m512 S2_f3221_zmm16r4(const __m512 k0a,
                                                const __m512 tht)  
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                        void S2_f3221_zmm16r4_a(const float * __restrict __attribute__((aligned(64)))  pk0a,
                                                const float * __restrict __attribute__((aligned(64)))  ptht,
                                                float * __restrict S2)
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                       void S2_f3221_zmm16r4_u(const float * __restrict  pk0a,
                                               const float * __restrict  ptht,
                                               float * __restrict S2)
                                                          __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 



                         /*
                         The E-plane and H-plane scattering cross sections.
                         Formula 3.2-22
                    */

                 ////////////////////////////////////////////////////////////////////////////////////////


                     __m512 rcs_f3222_zmm16r4(const __m512 k0a,
                                              const __m512 a,
                                              const __m512 theta)  
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                     void rcs_f3222_zmm16r4_a(  const float * __restrict __attribute__((aligned(64))) pk0a,
                                                const float * __restrict __attribute__((aligned(64))) pa,
                                                const float * __restrict __attribute__((aligned(64))) ptheta,
                                                float * __restrict __attribute__((aligned(64))) rcs )
                                                          __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                      void rcs_f3222_zmm16r4_u(  const float * __restrict  pk0a,
                                                 const float * __restrict  pa,
                                                 const float * __restrict ptheta,
                                                 float * __restrict  rcs ) {
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                          /*
                         The E-plane and H-plane scattering cross sections.
                         Formula 3.2-23
                    */


                //////////////////////////////////////////////////////////////////////////////////


                    __m512 rcs_f3223_zmm16r4(const __m512 k0a,
                                             const __m512 a,
                                             const __m512 theta)  
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                    void rcs_f3223_zmm16r4_a(  const float * __restrict __attribute__((aligned(64))) pk0a,
                                               const float * __restrict __attribute__((aligned(64))) pa,
                                               const float * __restrict __attribute__((aligned(64))) ptheta,
                                               float * __restrict __attribute__((aligned(64))) rcs  )
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                    void rcs_f3223_zmm16r4_u(  const float * __restrict  pk0a,
                                               const float * __restrict  pa,
                                               const float * __restrict  ptheta,
                                               float * __restrict  rcs  ) 
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                      /*
                        High frequency region (k0a > 20).
                        Complex scattering amplitudes.
                        Formula 3.2-24
                   */


                //////////////////////////////////////////////////////////////////////////////////////


                      void S12_f3224_zmm16r4( const __m512 k0a,
                                              const __m512 tht,
                                              __m512 * __restrict S12r,
                                              __m512 * __restrict S12i)
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));  


                       void S12_f3224_zmm16r4_a( const float * __restrict __attribute__((aligned(64))) pk0a,
                                                 const float * __restrict __attribute__((aligned(64))) ptht,
                                                 float * __restrict __attribute__((aligned(64))) S12r,
                                                 float * __restrict __attribute__((aligned(64))) S12i)
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                       void S12_f3224_zmm16r4_u( const float * __restrict  pk0a,
                                                 const float * __restrict  ptht,
                                                 float * __restrict  S12r,
                                                 float * __restrict  S12i)
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                           /*
                       Resonance region (0.4 < k0a < 20.0), equations are valid only for k0a < 1.0.
                       Complex scattering amplitude represented as a scattering function -- formula 3.2-26
                 */


             ///////////////////////////////////////////////////////////////////////////////////////////
 
                        
                       void S12_f3226_zmm16r4(const __m512 k0a,
                                              __m512 * __restrict S12r,
                                              __m512 * __restrict S12i)
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                       void S12_f3226_zmm16r4_a(const float * __restrict __attribute__((aligned(64))) pk0a,
                                                float * __restrict __attribute__((aligned(64))) S12r,
                                                float * __restrict __attribute__((aligned(64))) S12i)
                                                          __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                       void S12_f3226_zmm16r4_u(const float * __restrict  pk0a,
                                                float * __restrict  S12r,
                                                float * __restrict  S12i)
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                  /*
                           Resonance region (0.4 < k0a < 20.0), equations are valid only for k0a < 1.0.
                           Radar cross-section, formula 3.2-27
                     */


             /////////////////////////////////////////////////////////////////////////////////////////////


                       __m512 rcs_f3227_zmm16r4(const __m512 k0a,
                                                const __m512 a)  
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                       void rcs_f3227_zmm16r4_a(const float * __restrict __attribute__((aligned(64))) pk0a,
                                                const float * __restrict __attribute__((aligned(64))) pa,
                                                float * __restrict __attribute__((aligned(64))) rcs)
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                       void rcs_f3227_zmm16r4_u(const float * __restrict  pk0a,
                                                const float * __restrict  pa,
                                                float * __restrict  rcs) 
                                                          __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                    /*
                       Scattering functions equation at upper end of resonance region.
                       Optics wave term and creeping wave term.
                       Optics wave term, formula 3.2-28
                   */

               ////////////////////////////////////////////////////////////////////////////////////////////


                      void FO_f3228_zmm16r4(const __m512 k0a,
                                            __m512 * __restrict FOr,
                                            __m512 * __restrict FOi)      
                                                           __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                      void FO_f3228_zmm16r4_a(const float * __restrict __attribute__((aligned(64))) pk0a,
                                              float * __restrict __attribute__((aligned(64))) FOr,
                                              float * __restrict __attribute__((aligned(64))) FOi)
                                                            __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                      void FO_f3228_zmm16r4_u(const float * __restrict pk0a,
                                              float * __restrict FOr,
                                              float * __restrict FOi)
                                                             __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                        /*
                       Scattering functions equation at upper end of resonance region.
                       Optics wave term and creeping wave term.
                       Creeping wave term, formula 3.2-29
                   */


             /////////////////////////////////////////////////////////////////////////////////////////


                      void FC_f3229_zmm16r4(const __m512 x,
                                            __m512 * __restrict FCr,
                                            __m512 * __restrict FCi)
                                                            __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                       void FC_f3229_zmm16r4_a(const float * __restrict __attribute__((aligned(64))) px,
                                               float * __restrict __attribute__((aligned(64))) FCr,
                                               float * __restrict __attribute__((aligned(64))) FCi)
                                                           __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                      void FC_f3229_zmm16r4_u(const float * __restrict  px,
                                              float * __restrict  FCr,
                                              float * __restrict  FCi) 
                                                            __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));  


                        /*
                         Low frquency region (k0a < 0.4), Rayleigh approximation
                         for forward scattering function and cross-section.
                         Formulae: 3.2-31, 3.2-32
                         Forward scattering function.
                   */


              ////////////////////////////////////////////////////////////////////////////////////////


                       __m512 F_f3231_zmm16r4(const __m512 k0a)
                                                           __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));  


                       void F_f3231_zmm16r4_a(const float * __restrict __attribute__((aligned(64))) pk0a,
                                              float * __restrict __attribute__((aligned(64))) Fpi )
                                                             __attribute__((vectorcall))
                                                             __attribute__((noinline))
							     __attribute__((hot))
                                                             __attribute__((aligned(32)));  


                      void F_f3231_zmm16r4_u(const float * __restrict  pk0a,
                                             float * __restrict  Fpi) 
                                                             __attribute__((vectorcall))
                                                             __attribute__((noinline))
							     __attribute__((hot))
                                                             __attribute__((aligned(32)));  


                           /*
                         Low frquency region (k0a < 0.4), Rayleigh approximation
                         for forward scattering function and cross-section.
                         Formulae: 3.2-31, 3.2-32
                         RCS.
                   */

               ////////////////////////////////////////////////////////////////////////////////////////


                     __m512 rcs_f3232_zmm16r4(const __m512 k0a,
                                              const __m512 a)    
                                                          __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));  


                     void rcs_f3232_zmm16r4_a(  const float * __restrict __attribute__((aligned(64))) pk0a,
                                                const float * __restrict __attribute__((aligned(64))) pa,
                                                float * __restrict __attribute__((aligned(64))) rcs) 
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));  


                      void rcs_f3232_zmm16r4_u(  const float * __restrict  pk0a,
                                              const float * __restrict    pa,
                                              float * __restrict  rcs)
                                                          __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));  


                     /*
                         High-frequency region -- forward scattering function and 
                         cross-section (k0a > 20)
                         Formula 3.2-33 (Forward scattering function).
                     */


             /////////////////////////////////////////////////////////////////////////////////////////


                    void F_f3233_zmm16r4(const __m512 k0a,
                                        __m512 * __restrict Fr,
                                        __m512 * __restrict Fi)     
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));  


                    void F_f3233_zmm16r4_a(const float * __restrict __attribute__((aligned(64))) pk0a,
                                           float * __restrict __attribute__((aligned(64))) Fr,
                                           float * __restrict __attribute__((aligned(64))) Fi)  
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));  


                    void F_f3233_zmm16r4_u(const float * __restrict  pk0a,
                                          float * __restrict  Fr,
                                          float * __restrict  Fi)
                                                           __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                        /*
                         High-frequency region -- forward scattering function and 
                         cross-section (k0a > 20)
                         Formula 3.2-34 (RCS).
                     */


               /////////////////////////////////////////////////////////////////////////////////////////


                      __m512 rcs_f3234_zmm16r4(const __m512 k0a,
                                               const __m512 a)
                                                           __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                      void rcs_f3234_zmm16r4_a(const float * __restrict  __attribute__((aligned(64))) pk0a,
                                               const float * __restrict  __attribute__((aligned(64))) pa,
                                               float * __restrict  __attribute__((aligned(64))) rcs)
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                       void rcs_f3234_zmm16r4_u(const float * __restrict  pk0a,
                                                const float * __restrict  pa,
                                                float * __restrict  rcs)
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                        /*
                          Low-frequency region (k1a < 0.8).
                          Expansion by two series terms i.e. A0,A1 and B0,B1.
                          Formula 3.3-5
                    */


              //////////////////////////////////////////////////////////////////////////////////////////////////


                       void A_coffs_f335_zmm16r4(const __m512 k0a5,
                                                 const __m512 m1r,
                                                 const __m512 m1i,
                                                 __m512 * __restrict A1r,
                                                 __m512 * __restrict A1i,
                                                 __m512 * __restrict A2r,
                                                 __m512 * __restrict A2i)         
                                                           __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                        void A_coffs_f335_zmm16r4_a(const float * __restrict __attribute__((aligned(64)))  pk0a5,
                                               const float * __restrict __attribute__((aligned(64)))  pm1r,
                                               const float * __restrict __attribute__((aligned(64)))  pm1i,
                                               float * __restrict __attribute__((aligned(64)))  A1r,
                                               float * __restrict __attribute__((aligned(64)))  A1i,
                                               float * __restrict __attribute__((aligned(64)))  A2r,
                                               float * __restrict __attribute__((aligned(64)))  A2i) 
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                        void A_coffs_f335_zmm16r4_u(const float * __restrict  pk0a5,
                                                const float * __restrict  pm1r,
                                               const float * __restrict  pm1i,
                                               float * __restrict  A1r,
                                               float * __restrict  A1i,
                                               float * __restrict  A2r,
                                               float * __restrict  A2i) 
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                        void B_coffs_f335_zmm16r4(const __m512 k0a3,
                                             const __m512 k0a5,
                                             const __m512 m1r,
                                             const __m512 m1i,
                                             __m512 * __restrict B1r,
                                             __m512 * __restrict B1i,
                                             __m512 * __restrict B2r,
                                             __m512 * __restrict B2i)
                                                          __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                        void B_coffs_f335_zmm16r4_a(const float * __restrict __attribute__((aligned(64)))  pk0a3,
                                               const float * __restrict __attribute__((aligned(64)))  pk0a5,
                                               const float * __restrict __attribute__((aligned(64)))  pm1r,
                                               const float * __restrict __attribute__((aligned(64))) pm1i,
                                               float * __restrict __attribute__((aligned(64))) B1r,
                                               float * __restrict __attribute__((aligned(64))) B1i,
                                               float * __restrict __attribute__((aligned(64))) B2r,
                                               float * __restrict __attribute__((aligned(64))) B2i)
                                                            __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                        void B_coffs_f335_zmm16r4_u(const float * __restrict   pk0a3,
                                               const float * __restrict   pk0a5,
                                               const float * __restrict   pm1r,
                                               const float * __restrict   pm1i,
                                               float * __restrict  B1r,
                                               float * __restrict  B1i,
                                               float * __restrict  B2r,
                                               float * __restrict  B2i)
                                                              __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                      /*
                         Rayleigh backscattering RCS for dielectric spheres at angle 0.
                         Formula 3.3-7
                     */


               ///////////////////////////////////////////////////////////////////////////////////////////


                      __m512 rcs_f337_zmm16r4(const __m512 a,
                                           const __m512 k0a4,
                                           const __m512 m1r,
                                           const __m512 m1i) 
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                      void rcs_f337_zmm16r4_a(  const float * __restrict __attribute__((aligned(64))) pa,
                                           const float * __restrict __attribute__((aligned(64))) pk0a4,
                                           const float * __restrict __attribute__((aligned(64))) pm1r,
                                           const float * __restrict __attribute__((aligned(64))) pm1i,
                                           float * __restrict __attribute__((aligned(64))) rcs )
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                      void rcs_f337_zmm16r4_u(const float * __restrict  pa,
                                           const float * __restrict  pk0a4,
                                           const float * __restrict  pm1r,
                                           const float * __restrict  pm1i,
                                           float * __restrict  rcs )
                                                           __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                           /*
                        Low-frequency bi-static scattering
                  */


               //////////////////////////////////////////////////////////////////////////////


                      void S1_f338_zmm16r4(const __m512 ka03,
                                        const __m512 ka05,
                                        const __m512 tht,
                                        const __m512 mm1r,
                                        const __m512 mm1i,
                                        __m512 * __restrict S1r,
                                        __m512 * __restrict S1i)   
                                                          __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                      void S1_f338_zmm16r4_a(const float * __restrict __attribute__((aligned(64)))  pka03,
                                        const float * __restrict __attribute__((aligned(64))) pka05,
                                        const float * __restrict __attribute__((aligned(64))) ptht,
                                        const float * __restrict __attribute__((aligned(64))) pmm1r,
                                        const float * __restrict __attribute__((aligned(64))) pmm1i,
                                        float * __restrict __attribute__((aligned(64))) S1r,
                                        float * __restrict __attribute__((aligned(64))) S1i)
                                                           __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                       void S1_f338_zmm16r4_u(const float * __restrict  pka03,
                                        const float * __restrict  pka05,
                                        const float * __restrict  ptht,
                                        const float * __restrict  pmm1r,
                                        const float * __restrict  pmm1i,
                                        float * __restrict  S1r,
                                        float * __restrict  S1i)
                                                          __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                      void S2_f338_zmm16r4(const __m512 ka03,
                                        const __m512 ka05,
                                        const __m512 tht,
                                        const __m512 mm1r,
                                        const __m512 mm1i,
                                        __m512 * __restrict S2r,
                                        __m512 * __restrict S2i)  
                                                           __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                      void S2_f338_zmm16r4_a(const float * __restrict __attribute__((aligned(64))) pka03,
                                          const float * __restrict __attribute__((aligned(64))) pka05,
                                          const float * __restrict __attribute__((aligned(64))) ptht,
                                          const float * __restrict __attribute__((aligned(64))) pmm1r,
                                          const float * __restrict __attribute__((aligned(64))) pmm1i,
                                          float * __restrict __attribute__((aligned(64))) S2r,
                                          float * __restrict __attribute__((aligned(64))) S2i)
                                                          __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                      void S2_f338_zmm16r4_u(const float * __restrict  pka03,
                                          const float * __restrict  pka05,
                                          const float * __restrict  ptht,
                                          const float * __restrict  pmm1r,
                                          const float * __restrict  pmm1i,
                                          float * __restrict  S2r,
                                          float * __restrict  S2i) 
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                           /*
                         E-plane and H-plane RCS.
                         Formulae: 3.3-10,3.3-11
                     */


                ////////////////////////////////////////////////////////////////////////////////


                       __m512 rcs_f3310_zmm16r4(const __m512 tht,
                                            const __m512 a,
                                            const __m512 ka04,
                                            const __m512 mm1r,
                                            const __m512 mm1i)
                                                          __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32))); 


                        __m512 rcs_f3310_zmm16r4_a(const float * __restrict __attribute__((aligned(64))) ptht,
                                            const float * __restrict __attribute__((aligned(64))) pa,
                                            const float * __restrict __attribute__((aligned(64))) pka04,
                                            const float * __restrict __attribute__((aligned(64))) pmm1r,
                                            const float * __restrict __attribute__((aligned(64))) pmm1i)
                                                           __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                         __m512 rcs_f3310_zmm16r4_u(const float * __restrict  ptht,
                                              const float * __restrict  pa,
                                              const float * __restrict  pka04,
                                              const float * __restrict  pmm1r,
                                              const float * __restrict  pmm1i)
                                                           __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                         __m512 rcs_f3311_zmm16r4(const __m512 tht,
                                            const __m512 a,
                                            const __m512 ka04,
                                            const __m512 mm1r,
                                            const __m512 mm1i) 
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                         __m512 rcs_f3311_zmm16r4_a(const float * __restrict __attribute__((aligned(64))) ptht,
                                              const float * __restrict __attribute__((aligned(64))) pa,
                                              const float * __restrict __attribute__((aligned(64))) pka04,
                                              const float * __restrict __attribute__((aligned(64))) pmm1r,
                                              const float * __restrict __attribute__((aligned(64))) pmm1i)
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                        __m512 rcs_f3311_zmm16r4_u(const float * __restrict  ptht,
                                              const float * __restrict  pa,
                                              const float * __restrict  pka04,
                                              const float * __restrict  pmm1r,
                                              const float * __restrict  pmm1i) 
                                                           __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));

                        
                    /*
                          Bistatic Geometric Optics Rays.
                          The RCS of sphere included N-rays.
                          E-plane or H-plane, for backscattering
                          and forward-scattering E and H RCS are 
                          identical
                     */


                //////////////////////////////////////////////////////////////////////////////

#include <stdint.h>


                        __m512 rcs_f3314_zmm16r4(const __m512 * __restrict Snthr,
                                            const __m512 * __restrict Snthi,
                                            const __m512 * __restrict cjphr,
                                            const __m512 * __restrict cjphi,
                                            __m512 * __restrict wrkr,
                                            __m512 * __restrict wrki,
                                            const __m512 k02,
                                            const int32_t N)
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                          /*
                         Large sphere limit, k0a > 1.15/m1 (reflective region).
                         Backscattering RCS, formula 3.3-17
                    */


               /////////////////////////////////////////////////////////////////////////////////////


                     __m512 rcs_f3317_zmm16r4(const __m512 m1r,
                                             const __m512 m1i,
                                             const __m512 a) 
                                                        __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                      __m512 rcs_f3317_zmm16r4_a(const float * __restrict __attribute__((aligned(64))) pm1r,
                                              const float * __restrict __attribute__((aligned(64))) pm1i,
                                              const float * __restrict __attribute__((aligned(64))) pa)
                                                            __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                     __m512 rcs_f3317_zmm16r4_u(const float * __restrict  pm1r,
                                               const float * __restrict  pm1i,
                                               const float * __restrict  pa) 
                                                          __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                       /*
                       Forward scattering RCS.
                       Formula 3.3-19
                         */


                 /////////////////////////////////////////////////////////////////////////////////////////


                        __m512 rcs_f3319_zmm16r4(const __m512 a,
                                                 const __m512 k0a)
                                                             __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                         __m512 rcs_f3319_zmm16r4_a(const float * __restrict __attribute__((aligned(64))) pa,
                                                    const float * __restrict __attribute__((aligned(64))) pk0a)
                                                              __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                         __m512 rcs_f3319_zmm16r4_u(const float * __restrict  pa,
                                                    const float * __restrict  pk0a)
                                                             __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                            /*
                         Approximate solutions for far-field region (Rayleigh-Gans)
                         (abs(m1-1) << 1,2*k0a abs(m1-1) << 1)
                         Bistatic scattering formula 3.3-22
                     */


                  ///////////////////////////////////////////////////////////////////////////////////////////


                           void S1_f3322_zmm16r4(const __m512 m1r,
                                                 const __m512 m1i,
                                                 const __m512 tht,
                                                 const __m512 k0a,
                                                  __m512 * __restrict S1r,
                                                  __m512 * __restrict S1i)
                                                         __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                          void S1_f3322_zmm16r4_a(const float * __restrict __attribute__((aligned(64))) pm1r,
                                           const float * __restrict __attribute__((aligned(64))) pm1i,
                                           const float * __restrict __attribute__((aligned(64))) ptht,
                                           const float * __restrict __attribute__((aligned(64))) pk0a,
                                           float * __restrict __attribute__((aligned(64))) S1r,
                                           float * __restrict __attribute__((aligned(64))) S1i) 
                                                           __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));


                           void S1_f3322_zmm16r4_u(const float * __restrict  pm1r,
                                           const float * __restrict  pm1i,
                                           const float * __restrict  ptht,
                                           const float * __restrict  pk0a,
                                           float * __restrict S1r,
                                           float * __restrict  S1i) 
                                                           __attribute__((vectorcall))
                                                         __attribute__((noinline))
							 __attribute__((hot))
                                                         __attribute__((aligned(32)));













#endif /*__GMS_RCS_SPHERE_ZMM16R4_H__*/