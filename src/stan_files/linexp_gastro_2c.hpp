/*
This file is part of package gastempt

gastempt is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.18.0

#include <stan/model/model_header.hpp>

namespace model_linexp_gastro_2c_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

static int current_statement_begin__;

stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_linexp_gastro_2c");
    reader.add_event(98, 96, "end", "model_linexp_gastro_2c");
    return reader;
}

#include <meta_header.hpp>
 class model_linexp_gastro_2c : public prob_grad {
private:
    double lkj;
    int student_df;
    int n;
    int n_record;
    vector<int> record;
    vector_d minute;
    vector_d volume;
    vector_d volume_1;
    double norm_vol;
    int n_norm;
public:
    model_linexp_gastro_2c(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }

    model_linexp_gastro_2c(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, random_seed__, pstream__);
    }

    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;

        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning

        current_statement_begin__ = -1;

        static const char* function__ = "model_linexp_gastro_2c_namespace::model_linexp_gastro_2c";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        // initialize member variables
        try {
            current_statement_begin__ = 13;
            context__.validate_dims("data initialization", "lkj", "double", context__.to_vec());
            lkj = double(0);
            vals_r__ = context__.vals_r("lkj");
            pos__ = 0;
            lkj = vals_r__[pos__++];
            current_statement_begin__ = 14;
            context__.validate_dims("data initialization", "student_df", "int", context__.to_vec());
            student_df = int(0);
            vals_i__ = context__.vals_i("student_df");
            pos__ = 0;
            student_df = vals_i__[pos__++];
            current_statement_begin__ = 15;
            context__.validate_dims("data initialization", "n", "int", context__.to_vec());
            n = int(0);
            vals_i__ = context__.vals_i("n");
            pos__ = 0;
            n = vals_i__[pos__++];
            current_statement_begin__ = 16;
            context__.validate_dims("data initialization", "n_record", "int", context__.to_vec());
            n_record = int(0);
            vals_i__ = context__.vals_i("n_record");
            pos__ = 0;
            n_record = vals_i__[pos__++];
            current_statement_begin__ = 17;
            validate_non_negative_index("record", "n", n);
            context__.validate_dims("data initialization", "record", "int", context__.to_vec(n));
            validate_non_negative_index("record", "n", n);
            record = std::vector<int>(n,int(0));
            vals_i__ = context__.vals_i("record");
            pos__ = 0;
            size_t record_limit_0__ = n;
            for (size_t i_0__ = 0; i_0__ < record_limit_0__; ++i_0__) {
                record[i_0__] = vals_i__[pos__++];
            }
            current_statement_begin__ = 18;
            validate_non_negative_index("minute", "n", n);
            context__.validate_dims("data initialization", "minute", "vector_d", context__.to_vec(n));
            validate_non_negative_index("minute", "n", n);
            minute = vector_d(static_cast<Eigen::VectorXd::Index>(n));
            vals_r__ = context__.vals_r("minute");
            pos__ = 0;
            size_t minute_i_vec_lim__ = n;
            for (size_t i_vec__ = 0; i_vec__ < minute_i_vec_lim__; ++i_vec__) {
                minute[i_vec__] = vals_r__[pos__++];
            }
            current_statement_begin__ = 19;
            validate_non_negative_index("volume", "n", n);
            context__.validate_dims("data initialization", "volume", "vector_d", context__.to_vec(n));
            validate_non_negative_index("volume", "n", n);
            volume = vector_d(static_cast<Eigen::VectorXd::Index>(n));
            vals_r__ = context__.vals_r("volume");
            pos__ = 0;
            size_t volume_i_vec_lim__ = n;
            for (size_t i_vec__ = 0; i_vec__ < volume_i_vec_lim__; ++i_vec__) {
                volume[i_vec__] = vals_r__[pos__++];
            }

            // validate, data variables
            current_statement_begin__ = 13;
            current_statement_begin__ = 14;
            current_statement_begin__ = 15;
            check_greater_or_equal(function__,"n",n,0);
            current_statement_begin__ = 16;
            check_greater_or_equal(function__,"n_record",n_record,0);
            current_statement_begin__ = 17;
            current_statement_begin__ = 18;
            current_statement_begin__ = 19;
            // initialize data variables
            current_statement_begin__ = 23;
            validate_non_negative_index("volume_1", "n", n);
            volume_1 = vector_d(static_cast<Eigen::VectorXd::Index>(n));
            stan::math::fill(volume_1,DUMMY_VAR__);
            current_statement_begin__ = 24;
            norm_vol = double(0);
            stan::math::fill(norm_vol,DUMMY_VAR__);
            current_statement_begin__ = 25;
            n_norm = int(0);
            stan::math::fill(n_norm, std::numeric_limits<int>::min());

            current_statement_begin__ = 26;
            stan::math::assign(n_norm, 0);
            current_statement_begin__ = 27;
            stan::math::assign(norm_vol, 0);
            current_statement_begin__ = 29;
            for (int i = 1; i <= n; ++i) {

                current_statement_begin__ = 30;
                if (as_bool(logical_lt(get_base1(minute,i,"minute",1),5))) {

                    current_statement_begin__ = 31;
                    stan::math::assign(norm_vol, (norm_vol + get_base1(volume,i,"volume",1)));
                    current_statement_begin__ = 32;
                    stan::math::assign(n_norm, (n_norm + 1));
                }
            }
            current_statement_begin__ = 35;
            stan::math::assign(norm_vol, (norm_vol / n_norm));
            current_statement_begin__ = 36;
            stan::math::assign(volume_1, divide(volume,norm_vol));

            // validate transformed data
            current_statement_begin__ = 23;
            current_statement_begin__ = 24;
            current_statement_begin__ = 25;

            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 41;
            validate_non_negative_index("v0_1", "n_record", n_record);
            num_params_r__ += n_record;
            current_statement_begin__ = 42;
            validate_non_negative_index("sigma_record", "2", 2);
            num_params_r__ += 2;
            current_statement_begin__ = 43;
            ++num_params_r__;
            current_statement_begin__ = 44;
            ++num_params_r__;
            current_statement_begin__ = 45;
            ++num_params_r__;
            current_statement_begin__ = 46;
            validate_non_negative_index("L_rho", "2", 2);
            num_params_r__ += ((2 * (2 - 1)) / 2);
            current_statement_begin__ = 47;
        validate_non_negative_index("z", "2", 2);
            validate_non_negative_index("z", "n_record", n_record);
            num_params_r__ += 2 * n_record;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~model_linexp_gastro_2c() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        stan::io::writer<double> writer__(params_r__,params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        if (!(context__.contains_r("v0_1")))
            throw std::runtime_error("variable v0_1 missing");
        vals_r__ = context__.vals_r("v0_1");
        pos__ = 0U;
        validate_non_negative_index("v0_1", "n_record", n_record);
        context__.validate_dims("initialization", "v0_1", "vector_d", context__.to_vec(n_record));
        vector_d v0_1(static_cast<Eigen::VectorXd::Index>(n_record));
        for (int j1__ = 0U; j1__ < n_record; ++j1__)
            v0_1(j1__) = vals_r__[pos__++];
        try {
            writer__.vector_lub_unconstrain(0,2,v0_1);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable v0_1: ") + e.what());
        }

        if (!(context__.contains_r("sigma_record")))
            throw std::runtime_error("variable sigma_record missing");
        vals_r__ = context__.vals_r("sigma_record");
        pos__ = 0U;
        validate_non_negative_index("sigma_record", "2", 2);
        context__.validate_dims("initialization", "sigma_record", "vector_d", context__.to_vec(2));
        vector_d sigma_record(static_cast<Eigen::VectorXd::Index>(2));
        for (int j1__ = 0U; j1__ < 2; ++j1__)
            sigma_record(j1__) = vals_r__[pos__++];
        try {
            writer__.vector_lb_unconstrain(0,sigma_record);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable sigma_record: ") + e.what());
        }

        if (!(context__.contains_r("mu_kappa")))
            throw std::runtime_error("variable mu_kappa missing");
        vals_r__ = context__.vals_r("mu_kappa");
        pos__ = 0U;
        context__.validate_dims("initialization", "mu_kappa", "double", context__.to_vec());
        double mu_kappa(0);
        mu_kappa = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,mu_kappa);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable mu_kappa: ") + e.what());
        }

        if (!(context__.contains_r("mu_tempt")))
            throw std::runtime_error("variable mu_tempt missing");
        vals_r__ = context__.vals_r("mu_tempt");
        pos__ = 0U;
        context__.validate_dims("initialization", "mu_tempt", "double", context__.to_vec());
        double mu_tempt(0);
        mu_tempt = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,mu_tempt);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable mu_tempt: ") + e.what());
        }

        if (!(context__.contains_r("sigma")))
            throw std::runtime_error("variable sigma missing");
        vals_r__ = context__.vals_r("sigma");
        pos__ = 0U;
        context__.validate_dims("initialization", "sigma", "double", context__.to_vec());
        double sigma(0);
        sigma = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,sigma);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable sigma: ") + e.what());
        }

        if (!(context__.contains_r("L_rho")))
            throw std::runtime_error("variable L_rho missing");
        vals_r__ = context__.vals_r("L_rho");
        pos__ = 0U;
        validate_non_negative_index("L_rho", "2", 2);
        validate_non_negative_index("L_rho", "2", 2);
        context__.validate_dims("initialization", "L_rho", "matrix_d", context__.to_vec(2,2));
        matrix_d L_rho(static_cast<Eigen::VectorXd::Index>(2),static_cast<Eigen::VectorXd::Index>(2));
        for (int j2__ = 0U; j2__ < 2; ++j2__)
            for (int j1__ = 0U; j1__ < 2; ++j1__)
                L_rho(j1__,j2__) = vals_r__[pos__++];
        try {
            writer__.cholesky_corr_unconstrain(L_rho);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable L_rho: ") + e.what());
        }

        if (!(context__.contains_r("z")))
            throw std::runtime_error("variable z missing");
        vals_r__ = context__.vals_r("z");
        pos__ = 0U;
        validate_non_negative_index("z", "2", 2);
        validate_non_negative_index("z", "n_record", n_record);
        context__.validate_dims("initialization", "z", "matrix_d", context__.to_vec(2,n_record));
        matrix_d z(static_cast<Eigen::VectorXd::Index>(2),static_cast<Eigen::VectorXd::Index>(n_record));
        for (int j2__ = 0U; j2__ < n_record; ++j2__)
            for (int j1__ = 0U; j1__ < 2; ++j1__)
                z(j1__,j2__) = vals_r__[pos__++];
        try {
            writer__.matrix_unconstrain(z);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable z: ") + e.what());
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(vector<T__>& params_r__,
                 vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        typedef T__ local_scalar_t__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;

        try {
            // model parameters
            stan::io::reader<local_scalar_t__> in__(params_r__,params_i__);

            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  v0_1;
            (void) v0_1;  // dummy to suppress unused var warning
            if (jacobian__)
                v0_1 = in__.vector_lub_constrain(0,2,n_record,lp__);
            else
                v0_1 = in__.vector_lub_constrain(0,2,n_record);

            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  sigma_record;
            (void) sigma_record;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma_record = in__.vector_lb_constrain(0,2,lp__);
            else
                sigma_record = in__.vector_lb_constrain(0,2);

            local_scalar_t__ mu_kappa;
            (void) mu_kappa;  // dummy to suppress unused var warning
            if (jacobian__)
                mu_kappa = in__.scalar_lb_constrain(0,lp__);
            else
                mu_kappa = in__.scalar_lb_constrain(0);

            local_scalar_t__ mu_tempt;
            (void) mu_tempt;  // dummy to suppress unused var warning
            if (jacobian__)
                mu_tempt = in__.scalar_lb_constrain(0,lp__);
            else
                mu_tempt = in__.scalar_lb_constrain(0);

            local_scalar_t__ sigma;
            (void) sigma;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma = in__.scalar_lb_constrain(0,lp__);
            else
                sigma = in__.scalar_lb_constrain(0);

            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,Eigen::Dynamic>  L_rho;
            (void) L_rho;  // dummy to suppress unused var warning
            if (jacobian__)
                L_rho = in__.cholesky_corr_constrain(2,lp__);
            else
                L_rho = in__.cholesky_corr_constrain(2);

            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,Eigen::Dynamic>  z;
            (void) z;  // dummy to suppress unused var warning
            if (jacobian__)
                z = in__.matrix_constrain(2,n_record,lp__);
            else
                z = in__.matrix_constrain(2,n_record);


            // transformed parameters
            current_statement_begin__ = 51;
            validate_non_negative_index("cf", "n_record", n_record);
            validate_non_negative_index("cf", "2", 2);
            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,Eigen::Dynamic>  cf(static_cast<Eigen::VectorXd::Index>(n_record),static_cast<Eigen::VectorXd::Index>(2));
            (void) cf;  // dummy to suppress unused var warning

            stan::math::initialize(cf, DUMMY_VAR__);
            stan::math::fill(cf,DUMMY_VAR__);


            current_statement_begin__ = 52;
            stan::math::assign(cf, transpose(multiply(diag_pre_multiply(sigma_record,L_rho),z)));

            // validate transformed parameters
            for (int i0__ = 0; i0__ < n_record; ++i0__) {
                for (int i1__ = 0; i1__ < 2; ++i1__) {
                    if (stan::math::is_uninitialized(cf(i0__,i1__))) {
                        std::stringstream msg__;
                        msg__ << "Undefined transformed parameter: cf" << '[' << i0__ << ']' << '[' << i1__ << ']';
                        throw std::runtime_error(msg__.str());
                    }
                }
            }

            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 51;

            // model body
            {
            current_statement_begin__ = 56;
            int rec(0);
            (void) rec;  // dummy to suppress unused var warning

            stan::math::fill(rec, std::numeric_limits<int>::min());
            current_statement_begin__ = 57;
            local_scalar_t__ v0r;
            (void) v0r;  // dummy to suppress unused var warning

            stan::math::initialize(v0r, DUMMY_VAR__);
            stan::math::fill(v0r,DUMMY_VAR__);
            current_statement_begin__ = 58;
            local_scalar_t__ kappar;
            (void) kappar;  // dummy to suppress unused var warning

            stan::math::initialize(kappar, DUMMY_VAR__);
            stan::math::fill(kappar,DUMMY_VAR__);
            current_statement_begin__ = 59;
            local_scalar_t__ temptr;
            (void) temptr;  // dummy to suppress unused var warning

            stan::math::initialize(temptr, DUMMY_VAR__);
            stan::math::fill(temptr,DUMMY_VAR__);
            current_statement_begin__ = 60;
            validate_non_negative_index("mu", "n", n);
            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  mu(static_cast<Eigen::VectorXd::Index>(n));
            (void) mu;  // dummy to suppress unused var warning

            stan::math::initialize(mu, DUMMY_VAR__);
            stan::math::fill(mu,DUMMY_VAR__);


            current_statement_begin__ = 64;
            lp_accum__.add(lkj_corr_cholesky_log<propto__>(L_rho, lkj));
            current_statement_begin__ = 65;
            lp_accum__.add(normal_log<propto__>(to_vector(z), 0, 1));
            current_statement_begin__ = 67;
            lp_accum__.add(normal_log<propto__>(v0_1, 1, 0.29999999999999999));
            current_statement_begin__ = 68;
            lp_accum__.add(normal_log<propto__>(mu_kappa, 0.80000000000000004, 0.29999999999999999));
            current_statement_begin__ = 69;
            lp_accum__.add(normal_log<propto__>(mu_tempt, 40, 20));
            current_statement_begin__ = 70;
            lp_accum__.add(cauchy_log<propto__>(get_base1(sigma_record,1,"sigma_record",1), 0, 20));
            current_statement_begin__ = 71;
            lp_accum__.add(cauchy_log<propto__>(get_base1(sigma_record,2,"sigma_record",1), 0, 0.40000000000000002));
            current_statement_begin__ = 72;
            lp_accum__.add(cauchy_log<propto__>(sigma, 0.0, 0.20000000000000001));
            current_statement_begin__ = 74;
            for (int i = 1; i <= n; ++i) {

                current_statement_begin__ = 75;
                stan::math::assign(rec, get_base1(record,i,"record",1));
                current_statement_begin__ = 76;
                stan::math::assign(v0r, get_base1(v0_1,rec,"v0_1",1));
                current_statement_begin__ = 77;
                stan::math::assign(temptr, (mu_tempt + get_base1(cf,rec,1,"cf",1)));
                current_statement_begin__ = 78;
                stan::math::assign(kappar, (mu_kappa + get_base1(cf,rec,2,"cf",1)));
                current_statement_begin__ = 79;
                stan::model::assign(mu, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                            ((v0r * (1 + ((kappar * get_base1(minute,i,"minute",1)) / temptr))) * stan::math::exp((-(get_base1(minute,i,"minute",1)) / temptr))), 
                            "assigning variable mu");
            }
            current_statement_begin__ = 83;
            lp_accum__.add(student_t_log<propto__>(volume_1, student_df, mu, sigma));
            }

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("v0_1");
        names__.push_back("sigma_record");
        names__.push_back("mu_kappa");
        names__.push_back("mu_tempt");
        names__.push_back("sigma");
        names__.push_back("L_rho");
        names__.push_back("z");
        names__.push_back("cf");
        names__.push_back("v0");
        names__.push_back("tempt");
        names__.push_back("kappa");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(n_record);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(2);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(2);
        dims__.push_back(2);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(2);
        dims__.push_back(n_record);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(n_record);
        dims__.push_back(2);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(n_record);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(n_record);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(n_record);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;

        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__,params_i__);
        static const char* function__ = "model_linexp_gastro_2c_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        vector_d v0_1 = in__.vector_lub_constrain(0,2,n_record);
        vector_d sigma_record = in__.vector_lb_constrain(0,2);
        double mu_kappa = in__.scalar_lb_constrain(0);
        double mu_tempt = in__.scalar_lb_constrain(0);
        double sigma = in__.scalar_lb_constrain(0);
        matrix_d L_rho = in__.cholesky_corr_constrain(2);
        matrix_d z = in__.matrix_constrain(2,n_record);
            for (int k_0__ = 0; k_0__ < n_record; ++k_0__) {
            vars__.push_back(v0_1[k_0__]);
            }
            for (int k_0__ = 0; k_0__ < 2; ++k_0__) {
            vars__.push_back(sigma_record[k_0__]);
            }
        vars__.push_back(mu_kappa);
        vars__.push_back(mu_tempt);
        vars__.push_back(sigma);
            for (int k_1__ = 0; k_1__ < 2; ++k_1__) {
                for (int k_0__ = 0; k_0__ < 2; ++k_0__) {
                vars__.push_back(L_rho(k_0__, k_1__));
                }
            }
            for (int k_1__ = 0; k_1__ < n_record; ++k_1__) {
                for (int k_0__ = 0; k_0__ < 2; ++k_0__) {
                vars__.push_back(z(k_0__, k_1__));
                }
            }

        // declare and define transformed parameters
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        try {
            current_statement_begin__ = 51;
            validate_non_negative_index("cf", "n_record", n_record);
            validate_non_negative_index("cf", "2", 2);
            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,Eigen::Dynamic>  cf(static_cast<Eigen::VectorXd::Index>(n_record),static_cast<Eigen::VectorXd::Index>(2));
            (void) cf;  // dummy to suppress unused var warning

            stan::math::initialize(cf, DUMMY_VAR__);
            stan::math::fill(cf,DUMMY_VAR__);


            current_statement_begin__ = 52;
            stan::math::assign(cf, transpose(multiply(diag_pre_multiply(sigma_record,L_rho),z)));

            // validate transformed parameters
            current_statement_begin__ = 51;

            // write transformed parameters
            if (include_tparams__) {
            for (int k_1__ = 0; k_1__ < 2; ++k_1__) {
                for (int k_0__ = 0; k_0__ < n_record; ++k_0__) {
                vars__.push_back(cf(k_0__, k_1__));
                }
            }
            }
            if (!include_gqs__) return;
            // declare and define generated quantities
            current_statement_begin__ = 87;
            validate_non_negative_index("v0", "n_record", n_record);
            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  v0(static_cast<Eigen::VectorXd::Index>(n_record));
            (void) v0;  // dummy to suppress unused var warning

            stan::math::initialize(v0, DUMMY_VAR__);
            stan::math::fill(v0,DUMMY_VAR__);
            current_statement_begin__ = 88;
            validate_non_negative_index("tempt", "n_record", n_record);
            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  tempt(static_cast<Eigen::VectorXd::Index>(n_record));
            (void) tempt;  // dummy to suppress unused var warning

            stan::math::initialize(tempt, DUMMY_VAR__);
            stan::math::fill(tempt,DUMMY_VAR__);
            current_statement_begin__ = 89;
            validate_non_negative_index("kappa", "n_record", n_record);
            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  kappa(static_cast<Eigen::VectorXd::Index>(n_record));
            (void) kappa;  // dummy to suppress unused var warning

            stan::math::initialize(kappa, DUMMY_VAR__);
            stan::math::fill(kappa,DUMMY_VAR__);


            current_statement_begin__ = 91;
            stan::math::assign(v0, multiply(v0_1,norm_vol));
            current_statement_begin__ = 92;
            for (int i = 1; i <= n_record; ++i) {

                current_statement_begin__ = 93;
                stan::model::assign(tempt, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                            (mu_tempt + get_base1(cf,i,1,"cf",1)), 
                            "assigning variable tempt");
                current_statement_begin__ = 94;
                stan::model::assign(kappa, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                            (mu_kappa + get_base1(cf,i,2,"cf",1)), 
                            "assigning variable kappa");
            }

            // validate generated quantities
            current_statement_begin__ = 87;
            current_statement_begin__ = 88;
            current_statement_begin__ = 89;

            // write generated quantities
            for (int k_0__ = 0; k_0__ < n_record; ++k_0__) {
            vars__.push_back(v0[k_0__]);
            }
            for (int k_0__ = 0; k_0__ < n_record; ++k_0__) {
            vars__.push_back(tempt[k_0__]);
            }
            for (int k_0__ = 0; k_0__ < n_record; ++k_0__) {
            vars__.push_back(kappa[k_0__]);
            }

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng,params_r_vec,params_i_vec,vars_vec,include_tparams,include_gqs,pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    static std::string model_name() {
        return "model_linexp_gastro_2c";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        for (int k_0__ = 1; k_0__ <= n_record; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "v0_1" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= 2; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "sigma_record" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu_kappa";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu_tempt";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma";
        param_names__.push_back(param_name_stream__.str());
        for (int k_1__ = 1; k_1__ <= 2; ++k_1__) {
            for (int k_0__ = 1; k_0__ <= 2; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "L_rho" << '.' << k_0__ << '.' << k_1__;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        for (int k_1__ = 1; k_1__ <= n_record; ++k_1__) {
            for (int k_0__ = 1; k_0__ <= 2; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "z" << '.' << k_0__ << '.' << k_1__;
                param_names__.push_back(param_name_stream__.str());
            }
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
            for (int k_1__ = 1; k_1__ <= 2; ++k_1__) {
                for (int k_0__ = 1; k_0__ <= n_record; ++k_0__) {
                    param_name_stream__.str(std::string());
                    param_name_stream__ << "cf" << '.' << k_0__ << '.' << k_1__;
                    param_names__.push_back(param_name_stream__.str());
                }
            }
        }


        if (!include_gqs__) return;
        for (int k_0__ = 1; k_0__ <= n_record; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "v0" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= n_record; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "tempt" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= n_record; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "kappa" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        for (int k_0__ = 1; k_0__ <= n_record; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "v0_1" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= 2; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "sigma_record" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu_kappa";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu_tempt";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma";
        param_names__.push_back(param_name_stream__.str());
        for (int k_0__ = 1; k_0__ <= ((2 * (2 - 1)) / 2); ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "L_rho" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_1__ = 1; k_1__ <= n_record; ++k_1__) {
            for (int k_0__ = 1; k_0__ <= 2; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "z" << '.' << k_0__ << '.' << k_1__;
                param_names__.push_back(param_name_stream__.str());
            }
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
            for (int k_1__ = 1; k_1__ <= 2; ++k_1__) {
                for (int k_0__ = 1; k_0__ <= n_record; ++k_0__) {
                    param_name_stream__.str(std::string());
                    param_name_stream__ << "cf" << '.' << k_0__ << '.' << k_1__;
                    param_names__.push_back(param_name_stream__.str());
                }
            }
        }


        if (!include_gqs__) return;
        for (int k_0__ = 1; k_0__ <= n_record; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "v0" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= n_record; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "tempt" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= n_record; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "kappa" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
    }

}; // model

}

typedef model_linexp_gastro_2c_namespace::model_linexp_gastro_2c stan_model;


#endif