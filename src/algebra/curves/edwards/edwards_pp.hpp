/** @file
 *****************************************************************************
 * @author     This file is part of libsnark, developed by SCIPR Lab
 *             and contributors (see AUTHORS).
 * @copyright  MIT license (see LICENSE file)
 *****************************************************************************/

#ifndef EDWARDS_PP_HPP_
#define EDWARDS_PP_HPP_
#include "algebra/curves/public_params.hpp"
#include "algebra/curves/edwards/edwards_init.hpp"
#include "algebra/curves/edwards/edwards_g1.hpp"
#include "algebra/curves/edwards/edwards_g2.hpp"
#include "algebra/curves/edwards/edwards_pairing.hpp"

namespace libsnark {

class edwards_pp {
};

template<>
class EC_pp_selector<edwards_pp> {
public:
    typedef edwards_Fr Fp_type;
    typedef edwards_G1 G1_type;
    typedef edwards_G2 G2_type;
    typedef edwards_G1_precomp G1_precomp_type;
    typedef edwards_G2_precomp G2_precomp_type;
    typedef edwards_Fq Fq_type;
    typedef edwards_Fq3 Fqe_type;
    typedef edwards_Fq6 Fqk_type;
    typedef edwards_GT GT_type;
};

template<>
void init_public_params<edwards_pp>();

template<>
edwards_GT final_exponentiation<edwards_pp>(const edwards_Fq6 &elt);

template<>
edwards_G1_precomp precompute_G1<edwards_pp>(const edwards_G1 &P);

template<>
edwards_G2_precomp precompute_G2<edwards_pp>(const edwards_G2 &Q);

template<>
edwards_Fq6 miller_loop<edwards_pp>(const edwards_G1_precomp &prec_P,
                                    const edwards_G2_precomp &prec_Q);

template<>
edwards_Fq6 double_miller_loop<edwards_pp>(const edwards_G1_precomp &prec_P1,
                                           const edwards_G2_precomp &prec_Q1,
                                           const edwards_G1_precomp &prec_P2,
                                           const edwards_G2_precomp &prec_Q2);

/* the following are used in test files */

template<>
edwards_Fq6 pairing<edwards_pp>(const edwards_G1 &P,
                                const edwards_G2 &Q);

template<>
edwards_Fq6 reduced_pairing<edwards_pp>(const edwards_G1 &P,
                                        const edwards_G2 &Q);

} // libsnark
#endif // EDWARDS_PP_HPP_
