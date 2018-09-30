#pragma once

#include <boost/hana/detail/struct_macros.hpp>

#ifndef TUN_STRUCT_MACRO_HELPER_H
#define TUN_STRUCT_MACRO_HELPER_H

//////////////////////////////////////////////////////////////////////////////
// TUN_DEFINE_STRUCT
//////////////////////////////////////////////////////////////////////////////
#define TUN_DEFINE_STRUCT(...) \
	TUN_DEFINE_STRUCT_IMPL(BOOST_HANA_PP_NARG(__VA_ARGS__), __VA_ARGS__)

#define TUN_DEFINE_STRUCT_IMPL(N, ...) \
	BOOST_HANA_PP_CONCAT(TUN_DEFINE_STRUCT_IMPL_, N)(__VA_ARGS__)

#define TUN_DEFINE_STRUCT_IMPL_1(TYPE)      \
                                            \
	struct hana_accessors_impl {              \
		static constexpr auto apply() {         \
			struct member_names {                 \
				static constexpr auto get() {       \
					return ::boost::hana::make_tuple( \
                                            \
					);                                \
				}                                   \
			};                                    \
			return ::boost::hana::make_tuple(     \
                                            \
			);                                    \
		}                                       \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_2(TYPE, m1)                                              \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                \
                                                                                        \
	struct hana_accessors_impl {                                                          \
		static constexpr auto apply() {                                                     \
			struct member_names {                                                             \
				static constexpr auto get() {                                                   \
					return ::boost::hana::make_tuple(                                             \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1))); \
				}                                                                               \
			};                                                                                \
			return ::boost::hana::make_tuple(::boost::hana::make_pair(                        \
			    ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),         \
			    ::boost::hana::struct_detail::member_ptr<                                     \
			        decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),          \
			        &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}));               \
		}                                                                                   \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_3(TYPE, m1, m2)                                          \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                \
                                                                                        \
	struct hana_accessors_impl {                                                          \
		static constexpr auto apply() {                                                     \
			struct member_names {                                                             \
				static constexpr auto get() {                                                   \
					return ::boost::hana::make_tuple(                                             \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2))); \
				}                                                                               \
			};                                                                                \
			return ::boost::hana::make_tuple(                                                 \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}));           \
		}                                                                                   \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_4(TYPE, m1, m2, m3)                                      \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                \
                                                                                        \
	struct hana_accessors_impl {                                                          \
		static constexpr auto apply() {                                                     \
			struct member_names {                                                             \
				static constexpr auto get() {                                                   \
					return ::boost::hana::make_tuple(                                             \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3))); \
				}                                                                               \
			};                                                                                \
			return ::boost::hana::make_tuple(                                                 \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}));           \
		}                                                                                   \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_5(TYPE, m1, m2, m3, m4)                                  \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                \
                                                                                        \
	struct hana_accessors_impl {                                                          \
		static constexpr auto apply() {                                                     \
			struct member_names {                                                             \
				static constexpr auto get() {                                                   \
					return ::boost::hana::make_tuple(                                             \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4))); \
				}                                                                               \
			};                                                                                \
			return ::boost::hana::make_tuple(                                                 \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}));           \
		}                                                                                   \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_6(TYPE, m1, m2, m3, m4, m5)                              \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                \
                                                                                        \
	struct hana_accessors_impl {                                                          \
		static constexpr auto apply() {                                                     \
			struct member_names {                                                             \
				static constexpr auto get() {                                                   \
					return ::boost::hana::make_tuple(                                             \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5))); \
				}                                                                               \
			};                                                                                \
			return ::boost::hana::make_tuple(                                                 \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}));           \
		}                                                                                   \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_7(TYPE, m1, m2, m3, m4, m5, m6)                          \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                \
                                                                                        \
	struct hana_accessors_impl {                                                          \
		static constexpr auto apply() {                                                     \
			struct member_names {                                                             \
				static constexpr auto get() {                                                   \
					return ::boost::hana::make_tuple(                                             \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6))); \
				}                                                                               \
			};                                                                                \
			return ::boost::hana::make_tuple(                                                 \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}));           \
		}                                                                                   \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_8(TYPE, m1, m2, m3, m4, m5, m6, m7)                      \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                \
                                                                                        \
	struct hana_accessors_impl {                                                          \
		static constexpr auto apply() {                                                     \
			struct member_names {                                                             \
				static constexpr auto get() {                                                   \
					return ::boost::hana::make_tuple(                                             \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7))); \
				}                                                                               \
			};                                                                                \
			return ::boost::hana::make_tuple(                                                 \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}));           \
		}                                                                                   \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_9(TYPE, m1, m2, m3, m4, m5, m6, m7, m8)                  \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                \
                                                                                        \
	struct hana_accessors_impl {                                                          \
		static constexpr auto apply() {                                                     \
			struct member_names {                                                             \
				static constexpr auto get() {                                                   \
					return ::boost::hana::make_tuple(                                             \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8))); \
				}                                                                               \
			};                                                                                \
			return ::boost::hana::make_tuple(                                                 \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}));           \
		}                                                                                   \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_10(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9)             \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                \
                                                                                        \
	struct hana_accessors_impl {                                                          \
		static constexpr auto apply() {                                                     \
			struct member_names {                                                             \
				static constexpr auto get() {                                                   \
					return ::boost::hana::make_tuple(                                             \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9))); \
				}                                                                               \
			};                                                                                \
			return ::boost::hana::make_tuple(                                                 \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),            \
			    ::boost::hana::make_pair(                                                     \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                 \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}));           \
		}                                                                                   \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_11(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10)         \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_12(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11)    \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_13(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12)                                                   \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_14(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13)                                              \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_15(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14)                                         \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_16(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15)                                    \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_17(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16)                               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_18(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16, m17)                          \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_19(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16, m17, m18)                     \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m18)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18){BOOST_HANA_PP_BACK m18};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<17, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_20(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16, m17, m18, m19)                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m18)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18){BOOST_HANA_PP_BACK m18};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m19)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19){BOOST_HANA_PP_BACK m19};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<17, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<18, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_21(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16, m17, m18, m19, m20)           \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m18)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18){BOOST_HANA_PP_BACK m18};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m19)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19){BOOST_HANA_PP_BACK m19};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m20)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20){BOOST_HANA_PP_BACK m20};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<17, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<18, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<19, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_22(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16, m17, m18, m19, m20, m21)      \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m18)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18){BOOST_HANA_PP_BACK m18};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m19)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19){BOOST_HANA_PP_BACK m19};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m20)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20){BOOST_HANA_PP_BACK m20};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m21)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21){BOOST_HANA_PP_BACK m21};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<17, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<18, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<19, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<20, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_23(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22) \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m18)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18){BOOST_HANA_PP_BACK m18};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m19)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19){BOOST_HANA_PP_BACK m19};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m20)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20){BOOST_HANA_PP_BACK m20};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m21)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21){BOOST_HANA_PP_BACK m21};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m22)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22){BOOST_HANA_PP_BACK m22};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<17, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<18, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<19, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<20, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<21, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_24(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, \
                                  m23)                                                   \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m18)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18){BOOST_HANA_PP_BACK m18};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m19)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19){BOOST_HANA_PP_BACK m19};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m20)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20){BOOST_HANA_PP_BACK m20};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m21)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21){BOOST_HANA_PP_BACK m21};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m22)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22){BOOST_HANA_PP_BACK m22};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m23)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23){BOOST_HANA_PP_BACK m23};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<17, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<18, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<19, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<20, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<21, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<22, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_25(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, \
                                  m23, m24)                                              \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m18)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18){BOOST_HANA_PP_BACK m18};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m19)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19){BOOST_HANA_PP_BACK m19};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m20)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20){BOOST_HANA_PP_BACK m20};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m21)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21){BOOST_HANA_PP_BACK m21};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m22)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22){BOOST_HANA_PP_BACK m22};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m23)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23){BOOST_HANA_PP_BACK m23};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m24)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24){BOOST_HANA_PP_BACK m24};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<17, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<18, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<19, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<20, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<21, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<22, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<23, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_26(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, \
                                  m23, m24, m25)                                         \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m18)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18){BOOST_HANA_PP_BACK m18};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m19)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19){BOOST_HANA_PP_BACK m19};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m20)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20){BOOST_HANA_PP_BACK m20};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m21)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21){BOOST_HANA_PP_BACK m21};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m22)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22){BOOST_HANA_PP_BACK m22};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m23)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23){BOOST_HANA_PP_BACK m23};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m24)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24){BOOST_HANA_PP_BACK m24};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m25)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25){BOOST_HANA_PP_BACK m25};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<17, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<18, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<19, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<20, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<21, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<22, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<23, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<24, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_27(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, \
                                  m23, m24, m25, m26)                                    \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m18)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18){BOOST_HANA_PP_BACK m18};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m19)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19){BOOST_HANA_PP_BACK m19};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m20)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20){BOOST_HANA_PP_BACK m20};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m21)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21){BOOST_HANA_PP_BACK m21};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m22)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22){BOOST_HANA_PP_BACK m22};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m23)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23){BOOST_HANA_PP_BACK m23};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m24)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24){BOOST_HANA_PP_BACK m24};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m25)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25){BOOST_HANA_PP_BACK m25};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m26)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26){BOOST_HANA_PP_BACK m26};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<17, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<18, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<19, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<20, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<21, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<22, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<23, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<24, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<25, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_28(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, \
                                  m23, m24, m25, m26, m27)                               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m18)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18){BOOST_HANA_PP_BACK m18};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m19)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19){BOOST_HANA_PP_BACK m19};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m20)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20){BOOST_HANA_PP_BACK m20};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m21)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21){BOOST_HANA_PP_BACK m21};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m22)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22){BOOST_HANA_PP_BACK m22};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m23)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23){BOOST_HANA_PP_BACK m23};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m24)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24){BOOST_HANA_PP_BACK m24};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m25)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25){BOOST_HANA_PP_BACK m25};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m26)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26){BOOST_HANA_PP_BACK m26};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m27)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27){BOOST_HANA_PP_BACK m27};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<17, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<18, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<19, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<20, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<21, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<22, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<23, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<24, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<25, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<26, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_29(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, \
                                  m23, m24, m25, m26, m27, m28)                          \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m18)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18){BOOST_HANA_PP_BACK m18};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m19)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19){BOOST_HANA_PP_BACK m19};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m20)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20){BOOST_HANA_PP_BACK m20};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m21)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21){BOOST_HANA_PP_BACK m21};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m22)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22){BOOST_HANA_PP_BACK m22};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m23)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23){BOOST_HANA_PP_BACK m23};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m24)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24){BOOST_HANA_PP_BACK m24};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m25)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25){BOOST_HANA_PP_BACK m25};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m26)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26){BOOST_HANA_PP_BACK m26};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m27)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27){BOOST_HANA_PP_BACK m27};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m28)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28){BOOST_HANA_PP_BACK m28};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<17, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<18, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<19, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<20, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<21, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<22, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<23, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<24, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<25, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<26, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<27, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_30(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, \
                                  m23, m24, m25, m26, m27, m28, m29)                     \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m18)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18){BOOST_HANA_PP_BACK m18};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m19)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19){BOOST_HANA_PP_BACK m19};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m20)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20){BOOST_HANA_PP_BACK m20};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m21)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21){BOOST_HANA_PP_BACK m21};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m22)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22){BOOST_HANA_PP_BACK m22};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m23)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23){BOOST_HANA_PP_BACK m23};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m24)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24){BOOST_HANA_PP_BACK m24};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m25)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25){BOOST_HANA_PP_BACK m25};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m26)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26){BOOST_HANA_PP_BACK m26};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m27)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27){BOOST_HANA_PP_BACK m27};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m28)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28){BOOST_HANA_PP_BACK m28};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m29)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29){BOOST_HANA_PP_BACK m29};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<17, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<18, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<19, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<20, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<21, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<22, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<23, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<24, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<25, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<26, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<27, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<28, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_31(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, \
                                  m23, m24, m25, m26, m27, m28, m29, m30)                \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m18)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18){BOOST_HANA_PP_BACK m18};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m19)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19){BOOST_HANA_PP_BACK m19};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m20)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20){BOOST_HANA_PP_BACK m20};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m21)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21){BOOST_HANA_PP_BACK m21};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m22)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22){BOOST_HANA_PP_BACK m22};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m23)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23){BOOST_HANA_PP_BACK m23};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m24)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24){BOOST_HANA_PP_BACK m24};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m25)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25){BOOST_HANA_PP_BACK m25};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m26)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26){BOOST_HANA_PP_BACK m26};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m27)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27){BOOST_HANA_PP_BACK m27};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m28)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28){BOOST_HANA_PP_BACK m28};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m29)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29){BOOST_HANA_PP_BACK m29};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m30)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30){BOOST_HANA_PP_BACK m30};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<17, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<18, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<19, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<20, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<21, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<22, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<23, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<24, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<25, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<26, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<27, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<28, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<29, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_32(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, \
                                  m23, m24, m25, m26, m27, m28, m29, m30, m31)           \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m18)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18){BOOST_HANA_PP_BACK m18};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m19)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19){BOOST_HANA_PP_BACK m19};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m20)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20){BOOST_HANA_PP_BACK m20};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m21)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21){BOOST_HANA_PP_BACK m21};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m22)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22){BOOST_HANA_PP_BACK m22};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m23)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23){BOOST_HANA_PP_BACK m23};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m24)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24){BOOST_HANA_PP_BACK m24};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m25)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25){BOOST_HANA_PP_BACK m25};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m26)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26){BOOST_HANA_PP_BACK m26};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m27)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27){BOOST_HANA_PP_BACK m27};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m28)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28){BOOST_HANA_PP_BACK m28};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m29)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29){BOOST_HANA_PP_BACK m29};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m30)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30){BOOST_HANA_PP_BACK m30};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m31)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31){BOOST_HANA_PP_BACK m31};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<17, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<18, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<19, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<20, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<21, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<22, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<23, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<24, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<25, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<26, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<27, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<28, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<29, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<30, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_33(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, \
                                  m23, m24, m25, m26, m27, m28, m29, m30, m31, m32)      \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m18)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18){BOOST_HANA_PP_BACK m18};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m19)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19){BOOST_HANA_PP_BACK m19};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m20)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20){BOOST_HANA_PP_BACK m20};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m21)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21){BOOST_HANA_PP_BACK m21};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m22)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22){BOOST_HANA_PP_BACK m22};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m23)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23){BOOST_HANA_PP_BACK m23};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m24)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24){BOOST_HANA_PP_BACK m24};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m25)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25){BOOST_HANA_PP_BACK m25};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m26)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26){BOOST_HANA_PP_BACK m26};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m27)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27){BOOST_HANA_PP_BACK m27};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m28)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28){BOOST_HANA_PP_BACK m28};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m29)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29){BOOST_HANA_PP_BACK m29};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m30)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30){BOOST_HANA_PP_BACK m30};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m31)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31){BOOST_HANA_PP_BACK m31};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m32)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32){BOOST_HANA_PP_BACK m32};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<17, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<18, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<19, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<20, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<21, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<22, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<23, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<24, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<25, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<26, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<27, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<28, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<29, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<30, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<31, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_34(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, \
                                  m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33) \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m18)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18){BOOST_HANA_PP_BACK m18};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m19)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19){BOOST_HANA_PP_BACK m19};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m20)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20){BOOST_HANA_PP_BACK m20};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m21)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21){BOOST_HANA_PP_BACK m21};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m22)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22){BOOST_HANA_PP_BACK m22};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m23)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23){BOOST_HANA_PP_BACK m23};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m24)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24){BOOST_HANA_PP_BACK m24};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m25)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25){BOOST_HANA_PP_BACK m25};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m26)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26){BOOST_HANA_PP_BACK m26};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m27)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27){BOOST_HANA_PP_BACK m27};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m28)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28){BOOST_HANA_PP_BACK m28};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m29)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29){BOOST_HANA_PP_BACK m29};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m30)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30){BOOST_HANA_PP_BACK m30};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m31)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31){BOOST_HANA_PP_BACK m31};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m32)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32){BOOST_HANA_PP_BACK m32};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m33)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33){BOOST_HANA_PP_BACK m33};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<17, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<18, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<19, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<20, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<21, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<22, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<23, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<24, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<25, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<26, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<27, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<28, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<29, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<30, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<31, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<32, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_35(                                                       \
    TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17,    \
    m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, m34) \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m18)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18){BOOST_HANA_PP_BACK m18};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m19)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19){BOOST_HANA_PP_BACK m19};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m20)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20){BOOST_HANA_PP_BACK m20};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m21)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21){BOOST_HANA_PP_BACK m21};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m22)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22){BOOST_HANA_PP_BACK m22};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m23)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23){BOOST_HANA_PP_BACK m23};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m24)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24){BOOST_HANA_PP_BACK m24};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m25)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25){BOOST_HANA_PP_BACK m25};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m26)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26){BOOST_HANA_PP_BACK m26};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m27)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27){BOOST_HANA_PP_BACK m27};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m28)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28){BOOST_HANA_PP_BACK m28};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m29)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29){BOOST_HANA_PP_BACK m29};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m30)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30){BOOST_HANA_PP_BACK m30};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m31)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31){BOOST_HANA_PP_BACK m31};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m32)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32){BOOST_HANA_PP_BACK m32};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m33)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33){BOOST_HANA_PP_BACK m33};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m34)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34){BOOST_HANA_PP_BACK m34};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<17, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<18, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<19, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<20, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<21, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<22, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<23, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<24, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<25, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<26, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<27, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<28, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<29, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<30, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<31, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<32, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<33, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_36(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, \
                                  m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, \
                                  m34, m35)                                              \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m18)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18){BOOST_HANA_PP_BACK m18};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m19)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19){BOOST_HANA_PP_BACK m19};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m20)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20){BOOST_HANA_PP_BACK m20};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m21)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21){BOOST_HANA_PP_BACK m21};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m22)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22){BOOST_HANA_PP_BACK m22};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m23)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23){BOOST_HANA_PP_BACK m23};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m24)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24){BOOST_HANA_PP_BACK m24};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m25)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25){BOOST_HANA_PP_BACK m25};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m26)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26){BOOST_HANA_PP_BACK m26};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m27)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27){BOOST_HANA_PP_BACK m27};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m28)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28){BOOST_HANA_PP_BACK m28};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m29)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29){BOOST_HANA_PP_BACK m29};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m30)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30){BOOST_HANA_PP_BACK m30};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m31)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31){BOOST_HANA_PP_BACK m31};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m32)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32){BOOST_HANA_PP_BACK m32};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m33)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33){BOOST_HANA_PP_BACK m33};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m34)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34){BOOST_HANA_PP_BACK m34};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m35)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35){BOOST_HANA_PP_BACK m35};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<17, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<18, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<19, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<20, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<21, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<22, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<23, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<24, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<25, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<26, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<27, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<28, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<29, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<30, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<31, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<32, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<33, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<34, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_37(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, \
                                  m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, \
                                  m34, m35, m36)                                         \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m18)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18){BOOST_HANA_PP_BACK m18};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m19)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19){BOOST_HANA_PP_BACK m19};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m20)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20){BOOST_HANA_PP_BACK m20};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m21)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21){BOOST_HANA_PP_BACK m21};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m22)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22){BOOST_HANA_PP_BACK m22};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m23)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23){BOOST_HANA_PP_BACK m23};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m24)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24){BOOST_HANA_PP_BACK m24};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m25)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25){BOOST_HANA_PP_BACK m25};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m26)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26){BOOST_HANA_PP_BACK m26};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m27)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27){BOOST_HANA_PP_BACK m27};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m28)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28){BOOST_HANA_PP_BACK m28};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m29)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29){BOOST_HANA_PP_BACK m29};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m30)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30){BOOST_HANA_PP_BACK m30};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m31)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31){BOOST_HANA_PP_BACK m31};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m32)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32){BOOST_HANA_PP_BACK m32};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m33)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33){BOOST_HANA_PP_BACK m33};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m34)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34){BOOST_HANA_PP_BACK m34};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m35)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35){BOOST_HANA_PP_BACK m35};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m36)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m36){BOOST_HANA_PP_BACK m36};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m36))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<17, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<18, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<19, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<20, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<21, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<22, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<23, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<24, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<25, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<26, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<27, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<28, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<29, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<30, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<31, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<32, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<33, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<34, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<35, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m36)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m36)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_38(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, \
                                  m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, \
                                  m34, m35, m36, m37)                                    \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m18)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18){BOOST_HANA_PP_BACK m18};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m19)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19){BOOST_HANA_PP_BACK m19};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m20)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20){BOOST_HANA_PP_BACK m20};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m21)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21){BOOST_HANA_PP_BACK m21};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m22)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22){BOOST_HANA_PP_BACK m22};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m23)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23){BOOST_HANA_PP_BACK m23};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m24)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24){BOOST_HANA_PP_BACK m24};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m25)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25){BOOST_HANA_PP_BACK m25};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m26)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26){BOOST_HANA_PP_BACK m26};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m27)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27){BOOST_HANA_PP_BACK m27};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m28)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28){BOOST_HANA_PP_BACK m28};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m29)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29){BOOST_HANA_PP_BACK m29};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m30)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30){BOOST_HANA_PP_BACK m30};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m31)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31){BOOST_HANA_PP_BACK m31};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m32)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32){BOOST_HANA_PP_BACK m32};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m33)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33){BOOST_HANA_PP_BACK m33};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m34)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34){BOOST_HANA_PP_BACK m34};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m35)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35){BOOST_HANA_PP_BACK m35};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m36)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m36){BOOST_HANA_PP_BACK m36};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m37)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m37){BOOST_HANA_PP_BACK m37};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m36)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m37))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<17, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<18, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<19, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<20, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<21, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<22, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<23, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<24, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<25, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<26, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<27, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<28, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<29, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<30, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<31, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<32, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<33, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<34, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<35, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m36)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m36)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<36, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m37)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m37)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_39(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, \
                                  m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, \
                                  m34, m35, m36, m37, m38)                               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m18)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18){BOOST_HANA_PP_BACK m18};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m19)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19){BOOST_HANA_PP_BACK m19};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m20)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20){BOOST_HANA_PP_BACK m20};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m21)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21){BOOST_HANA_PP_BACK m21};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m22)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22){BOOST_HANA_PP_BACK m22};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m23)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23){BOOST_HANA_PP_BACK m23};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m24)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24){BOOST_HANA_PP_BACK m24};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m25)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25){BOOST_HANA_PP_BACK m25};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m26)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26){BOOST_HANA_PP_BACK m26};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m27)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27){BOOST_HANA_PP_BACK m27};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m28)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28){BOOST_HANA_PP_BACK m28};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m29)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29){BOOST_HANA_PP_BACK m29};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m30)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30){BOOST_HANA_PP_BACK m30};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m31)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31){BOOST_HANA_PP_BACK m31};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m32)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32){BOOST_HANA_PP_BACK m32};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m33)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33){BOOST_HANA_PP_BACK m33};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m34)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34){BOOST_HANA_PP_BACK m34};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m35)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35){BOOST_HANA_PP_BACK m35};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m36)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m36){BOOST_HANA_PP_BACK m36};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m37)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m37){BOOST_HANA_PP_BACK m37};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m38)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m38){BOOST_HANA_PP_BACK m38};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m36)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m37)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m38))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<17, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<18, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<19, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<20, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<21, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<22, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<23, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<24, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<25, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<26, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<27, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<28, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<29, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<30, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<31, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<32, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<33, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<34, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<35, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m36)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m36)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<36, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m37)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m37)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<37, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m38)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m38)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_40(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, \
                                  m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, \
                                  m34, m35, m36, m37, m38, m39)                          \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m18)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18){BOOST_HANA_PP_BACK m18};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m19)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19){BOOST_HANA_PP_BACK m19};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m20)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20){BOOST_HANA_PP_BACK m20};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m21)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21){BOOST_HANA_PP_BACK m21};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m22)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22){BOOST_HANA_PP_BACK m22};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m23)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23){BOOST_HANA_PP_BACK m23};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m24)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24){BOOST_HANA_PP_BACK m24};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m25)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25){BOOST_HANA_PP_BACK m25};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m26)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26){BOOST_HANA_PP_BACK m26};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m27)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27){BOOST_HANA_PP_BACK m27};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m28)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28){BOOST_HANA_PP_BACK m28};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m29)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29){BOOST_HANA_PP_BACK m29};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m30)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30){BOOST_HANA_PP_BACK m30};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m31)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31){BOOST_HANA_PP_BACK m31};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m32)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32){BOOST_HANA_PP_BACK m32};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m33)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33){BOOST_HANA_PP_BACK m33};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m34)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34){BOOST_HANA_PP_BACK m34};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m35)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35){BOOST_HANA_PP_BACK m35};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m36)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m36){BOOST_HANA_PP_BACK m36};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m37)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m37){BOOST_HANA_PP_BACK m37};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m38)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m38){BOOST_HANA_PP_BACK m38};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m39)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m39){BOOST_HANA_PP_BACK m39};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m36)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m37)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m38)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m39))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<17, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<18, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<19, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<20, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<21, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<22, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<23, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<24, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<25, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<26, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<27, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<28, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<29, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<30, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<31, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<32, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<33, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<34, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<35, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m36)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m36)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<36, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m37)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m37)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<37, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m38)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m38)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<38, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m39)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m39)>{}));           \
		}                                                                                    \
	} /**/

#define TUN_DEFINE_STRUCT_IMPL_41(TYPE, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11,    \
                                  m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, \
                                  m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, \
                                  m34, m35, m36, m37, m38, m39, m40)                     \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m1)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1){BOOST_HANA_PP_BACK m1};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m2)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2){BOOST_HANA_PP_BACK m2};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m3)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3){BOOST_HANA_PP_BACK m3};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m4)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4){BOOST_HANA_PP_BACK m4};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m5)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5){BOOST_HANA_PP_BACK m5};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m6)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6){BOOST_HANA_PP_BACK m6};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m7)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7){BOOST_HANA_PP_BACK m7};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m8)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8){BOOST_HANA_PP_BACK m8};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m9)                                    \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9){BOOST_HANA_PP_BACK m9};                 \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m10)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10){BOOST_HANA_PP_BACK m10};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m11)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11){BOOST_HANA_PP_BACK m11};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m12)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12){BOOST_HANA_PP_BACK m12};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m13)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13){BOOST_HANA_PP_BACK m13};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m14)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14){BOOST_HANA_PP_BACK m14};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m15)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15){BOOST_HANA_PP_BACK m15};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m16)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16){BOOST_HANA_PP_BACK m16};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m17)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17){BOOST_HANA_PP_BACK m17};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m18)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18){BOOST_HANA_PP_BACK m18};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m19)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19){BOOST_HANA_PP_BACK m19};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m20)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20){BOOST_HANA_PP_BACK m20};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m21)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21){BOOST_HANA_PP_BACK m21};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m22)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22){BOOST_HANA_PP_BACK m22};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m23)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23){BOOST_HANA_PP_BACK m23};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m24)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24){BOOST_HANA_PP_BACK m24};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m25)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25){BOOST_HANA_PP_BACK m25};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m26)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26){BOOST_HANA_PP_BACK m26};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m27)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27){BOOST_HANA_PP_BACK m27};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m28)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28){BOOST_HANA_PP_BACK m28};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m29)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29){BOOST_HANA_PP_BACK m29};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m30)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30){BOOST_HANA_PP_BACK m30};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m31)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31){BOOST_HANA_PP_BACK m31};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m32)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32){BOOST_HANA_PP_BACK m32};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m33)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33){BOOST_HANA_PP_BACK m33};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m34)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34){BOOST_HANA_PP_BACK m34};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m35)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35){BOOST_HANA_PP_BACK m35};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m36)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m36){BOOST_HANA_PP_BACK m36};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m37)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m37){BOOST_HANA_PP_BACK m37};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m38)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m38){BOOST_HANA_PP_BACK m38};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m39)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m39){BOOST_HANA_PP_BACK m39};               \
	BOOST_HANA_PP_DROP_BACK(BOOST_HANA_PP_DROP_BACK m40)                                   \
	BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m40){BOOST_HANA_PP_BACK m40};               \
                                                                                         \
	struct hana_accessors_impl {                                                           \
		static constexpr auto apply() {                                                      \
			struct member_names {                                                              \
				static constexpr auto get() {                                                    \
					return ::boost::hana::make_tuple(                                              \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),   \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m36)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m37)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m38)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m39)),  \
					    BOOST_HANA_PP_STRINGIZE(BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m40))); \
				}                                                                                \
			};                                                                                 \
			return ::boost::hana::make_tuple(                                                  \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<0, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m1)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<1, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m2)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<2, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m3)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<3, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m4)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<4, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m5)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<5, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m6)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<6, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m7)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<7, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m8)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<8, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)),       \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m9)>{}),             \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<9, member_names>(),      \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m10)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<10, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m11)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<11, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m12)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<12, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m13)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<13, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m14)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<14, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m15)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<15, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m16)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<16, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m17)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<17, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m18)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<18, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m19)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<19, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m20)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<20, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m21)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<21, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m22)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<22, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m23)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<23, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m24)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<24, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m25)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<25, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m26)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<26, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m27)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<27, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m28)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<28, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m29)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<29, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m30)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<30, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m31)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<31, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m32)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<32, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m33)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<33, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m34)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<34, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m35)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<35, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m36)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m36)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<36, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m37)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m37)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<37, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m38)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m38)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<38, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m39)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m39)>{}),            \
			    ::boost::hana::make_pair(                                                      \
			        ::boost::hana::struct_detail::prepare_member_name<39, member_names>(),     \
			        ::boost::hana::struct_detail::member_ptr<                                  \
			            decltype(&TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m40)),      \
			            &TYPE::BOOST_HANA_PP_BACK(BOOST_HANA_PP_DROP_BACK m40)>{}));           \
		}                                                                                    \
	} /**/

#endif  // TUN_STRUCT_MACRO_HELPER_H
