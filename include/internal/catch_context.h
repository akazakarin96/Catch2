/*
 *  Created by Phil on 31/12/2010.
 *  Copyright 2010 Two Blue Cubes Ltd. All rights reserved.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef TWOBLUECUBES_CATCH_CONTEXT_H_INCLUDED
#define TWOBLUECUBES_CATCH_CONTEXT_H_INCLUDED

#include "catch_ptr.hpp"

#include <memory>
#include <vector>
#include <stdlib.h>

namespace Catch {

    class TestCase;
    class Stream;
    struct IRunContext;
    struct IRunner;
    struct IConfig;

    struct IContext
    {
        virtual ~IContext();

        virtual IRunContext* getCurrentRunContext() = 0;
        virtual IRunner* getRunner() = 0;
        virtual IConfig const* getConfig() const = 0;
    };

    struct IMutableContext : IContext
    {
        virtual ~IMutableContext();
        virtual void setResultCapture( IRunContext* resultCapture ) = 0;
        virtual void setRunner( IRunner* runner ) = 0;
        virtual void setConfig( Ptr<IConfig const> const& config ) = 0;
    };

    IContext& getCurrentContext();
    IMutableContext& getCurrentMutableContext();
    void cleanUpContext();
    IConfig const* getCurrentConfig();
}

#endif // TWOBLUECUBES_CATCH_CONTEXT_H_INCLUDED
