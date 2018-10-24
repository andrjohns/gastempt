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

namespace model_linexp_gastro_1c_namespace {

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
    reader.add_event(0, 0, "start", "model_linexp_gastro_1c");
    reader.add_event(40, 38, "end", "model_linexp_gastro_1c");
    return reader;
}

#include <meta_header.hpp>
 class model_linexp_gastro_1c : public prob_grad {
private:
    double prior_v0;
    int n;
    int n_record;
    vector<int> record;
    vector_d minute;
    vector_d volume;
public:
    model_linexp_gastro_1c(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }

    model_linexp_gastro_1c(stan::io::var_context& context__,
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

        static const char* function__ = "model_linexp_gastro_1c_namespace::model_linexp_gastro_1c";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        // initialize member variables
        try {
            current_statement_begin__ = 6;
            context__.validate_dims("data initialization", "prior_v0", "double", context__.to_vec());
            prior_v0 = double(0);
            vals_r__ = context__.vals_r("prior_v0");
            pos__ = 0;
            prior_v0 = vals_r__[pos__++];
            current_statement_begin__ = 7;
            context__.validate_dims("data initialization", "n", "int", context__.to_vec());
            n = int(0);
            vals_i__ = context__.vals_i("n");
            pos__ = 0;
            n = vals_i__[pos__++];
            current_statement_begin__ = 8;
            context__.validate_dims("data initialization", "n_record", "int", context__.to_vec());
            n_record = int(0);
            vals_i__ = context__.vals_i("n_record");
            pos__ = 0;
            n_record = vals_i__[pos__++];
            current_statement_begin__ = 9;
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
            current_statement_begin__ = 10;
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
            current_statement_begin__ = 11;
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
            current_statement_begin__ = 6;
            current_statement_begin__ = 7;
            check_greater_or_equal(function__,"n",n,0);
            current_statement_begin__ = 8;
            check_greater_or_equal(function__,"n_record",n_record,0);
            current_statement_begin__ = 9;
            current_statement_begin__ = 10;
            current_statement_begin__ = 11;
            // initialize data variables


            // validate transformed data

            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 15;
            validate_non_negative_index("v0", "n_record", n_record);
            num_params_r__ += n_record;
            current_statement_begin__ = 16;
            validate_non_negative_index("kappa", "n_record", n_record);
            num_params_r__ += n_record;
            current_statement_begin__ = 17;
            validate_non_negative_index("tempt", "n_record", n_record);
            num_params_r__ += n_record;
            current_statement_begin__ = 18;
            ++num_params_r__;
            current_statement_begin__ = 19;
            ++num_params_r__;
            current_statement_begin__ = 20;
            ++num_params_r__;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~model_linexp_gastro_1c() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        stan::io::writer<double> writer__(params_r__,params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        if (!(context__.contains_r("v0")))
            throw std::runtime_error("variable v0 missing");
        vals_r__ = context__.vals_r("v0");
        pos__ = 0U;
        validate_non_negative_index("v0", "n_record", n_record);
        context__.validate_dims("initialization", "v0", "vector_d", context__.to_vec(n_record));
        vector_d v0(static_cast<Eigen::VectorXd::Index>(n_record));
        for (int j1__ = 0U; j1__ < n_record; ++j1__)
            v0(j1__) = vals_r__[pos__++];
        try {
            writer__.vector_lb_unconstrain(0,v0);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable v0: ") + e.what());
        }

        if (!(context__.contains_r("kappa")))
            throw std::runtime_error("variable kappa missing");
        vals_r__ = context__.vals_r("kappa");
        pos__ = 0U;
        validate_non_negative_index("kappa", "n_record", n_record);
        context__.validate_dims("initialization", "kappa", "vector_d", context__.to_vec(n_record));
        vector_d kappa(static_cast<Eigen::VectorXd::Index>(n_record));
        for (int j1__ = 0U; j1__ < n_record; ++j1__)
            kappa(j1__) = vals_r__[pos__++];
        try {
            writer__.vector_lb_unconstrain(0,kappa);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable kappa: ") + e.what());
        }

        if (!(context__.contains_r("tempt")))
            throw std::runtime_error("variable tempt missing");
        vals_r__ = context__.vals_r("tempt");
        pos__ = 0U;
        validate_non_negative_index("tempt", "n_record", n_record);
        context__.validate_dims("initialization", "tempt", "vector_d", context__.to_vec(n_record));
        vector_d tempt(static_cast<Eigen::VectorXd::Index>(n_record));
        for (int j1__ = 0U; j1__ < n_record; ++j1__)
            tempt(j1__) = vals_r__[pos__++];
        try {
            writer__.vector_lb_unconstrain(0,tempt);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable tempt: ") + e.what());
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

        if (!(context__.contains_r("sigma_kappa")))
            throw std::runtime_error("variable sigma_kappa missing");
        vals_r__ = context__.vals_r("sigma_kappa");
        pos__ = 0U;
        context__.validate_dims("initialization", "sigma_kappa", "double", context__.to_vec());
        double sigma_kappa(0);
        sigma_kappa = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,sigma_kappa);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable sigma_kappa: ") + e.what());
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

            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  v0;
            (void) v0;  // dummy to suppress unused var warning
            if (jacobian__)
                v0 = in__.vector_lb_constrain(0,n_record,lp__);
            else
                v0 = in__.vector_lb_constrain(0,n_record);

            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  kappa;
            (void) kappa;  // dummy to suppress unused var warning
            if (jacobian__)
                kappa = in__.vector_lb_constrain(0,n_record,lp__);
            else
                kappa = in__.vector_lb_constrain(0,n_record);

            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  tempt;
            (void) tempt;  // dummy to suppress unused var warning
            if (jacobian__)
                tempt = in__.vector_lb_constrain(0,n_record,lp__);
            else
                tempt = in__.vector_lb_constrain(0,n_record);

            local_scalar_t__ sigma;
            (void) sigma;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma = in__.scalar_lb_constrain(0,lp__);
            else
                sigma = in__.scalar_lb_constrain(0);

            local_scalar_t__ mu_kappa;
            (void) mu_kappa;  // dummy to suppress unused var warning
            if (jacobian__)
                mu_kappa = in__.scalar_lb_constrain(0,lp__);
            else
                mu_kappa = in__.scalar_lb_constrain(0);

            local_scalar_t__ sigma_kappa;
            (void) sigma_kappa;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma_kappa = in__.scalar_lb_constrain(0,lp__);
            else
                sigma_kappa = in__.scalar_lb_constrain(0);


            // transformed parameters



            // validate transformed parameters

            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning

            // model body
            {
            current_statement_begin__ = 25;
            validate_non_negative_index("vol", "n", n);
            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  vol(static_cast<Eigen::VectorXd::Index>(n));
            (void) vol;  // dummy to suppress unused var warning

            stan::math::initialize(vol, DUMMY_VAR__);
            stan::math::fill(vol,DUMMY_VAR__);


            current_statement_begin__ = 26;
            lp_accum__.add(normal_log<propto__>(mu_kappa, 1.5, 0.5));
            current_statement_begin__ = 27;
            lp_accum__.add(normal_log<propto__>(sigma_kappa, 1, 0.5));
            current_statement_begin__ = 29;
            lp_accum__.add(normal_log<propto__>(v0, prior_v0, 100));
            current_statement_begin__ = 30;
            lp_accum__.add(lognormal_log<propto__>(kappa, mu_kappa, sigma_kappa));
            current_statement_begin__ = 31;
            lp_accum__.add(normal_log<propto__>(tempt, 60, 20));
            current_statement_begin__ = 32;
            lp_accum__.add(gamma_log<propto__>(sigma, 20, 0.5));
            current_statement_begin__ = 33;
            stan::math::assign(vol, elt_multiply(elt_multiply(stan::model::rvalue(v0, stan::model::cons_list(stan::model::index_multi(record), stan::model::nil_index_list()), "v0"),add(1,elt_multiply(stan::model::rvalue(kappa, stan::model::cons_list(stan::model::index_multi(record), stan::model::nil_index_list()), "kappa"),elt_divide(minute,stan::model::rvalue(tempt, stan::model::cons_list(stan::model::index_multi(record), stan::model::nil_index_list()), "tempt"))))),stan::math::exp(elt_divide(minus(minute),stan::model::rvalue(tempt, stan::model::cons_list(stan::model::index_multi(record), stan::model::nil_index_list()), "tempt")))));
            current_statement_begin__ = 35;
            lp_accum__.add(normal_log<propto__>(volume, vol, sigma));
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
        names__.push_back("v0");
        names__.push_back("kappa");
        names__.push_back("tempt");
        names__.push_back("sigma");
        names__.push_back("mu_kappa");
        names__.push_back("sigma_kappa");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(n_record);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(n_record);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(n_record);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
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
        static const char* function__ = "model_linexp_gastro_1c_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        vector_d v0 = in__.vector_lb_constrain(0,n_record);
        vector_d kappa = in__.vector_lb_constrain(0,n_record);
        vector_d tempt = in__.vector_lb_constrain(0,n_record);
        double sigma = in__.scalar_lb_constrain(0);
        double mu_kappa = in__.scalar_lb_constrain(0);
        double sigma_kappa = in__.scalar_lb_constrain(0);
            for (int k_0__ = 0; k_0__ < n_record; ++k_0__) {
            vars__.push_back(v0[k_0__]);
            }
            for (int k_0__ = 0; k_0__ < n_record; ++k_0__) {
            vars__.push_back(kappa[k_0__]);
            }
            for (int k_0__ = 0; k_0__ < n_record; ++k_0__) {
            vars__.push_back(tempt[k_0__]);
            }
        vars__.push_back(sigma);
        vars__.push_back(mu_kappa);
        vars__.push_back(sigma_kappa);

        // declare and define transformed parameters
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        try {



            // validate transformed parameters

            // write transformed parameters
            if (include_tparams__) {
            }
            if (!include_gqs__) return;
            // declare and define generated quantities



            // validate generated quantities

            // write generated quantities
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
        return "model_linexp_gastro_1c";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        for (int k_0__ = 1; k_0__ <= n_record; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "v0" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= n_record; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "kappa" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= n_record; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "tempt" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu_kappa";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_kappa";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
        }


        if (!include_gqs__) return;
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        for (int k_0__ = 1; k_0__ <= n_record; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "v0" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= n_record; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "kappa" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= n_record; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "tempt" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu_kappa";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_kappa";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
        }


        if (!include_gqs__) return;
    }

}; // model

}

typedef model_linexp_gastro_1c_namespace::model_linexp_gastro_1c stan_model;


#endif
