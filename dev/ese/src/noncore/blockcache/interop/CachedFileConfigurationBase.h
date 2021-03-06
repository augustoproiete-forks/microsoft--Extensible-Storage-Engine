// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#include "stdafx.h"

#pragma once

namespace Internal
{
    namespace Ese
    {
        namespace BlockCache
        {
            namespace Interop
            {
                template< class TM, class TN, class TW >
                public ref class CachedFileConfigurationBase : public Base<TM, TN, TW>, ICachedFileConfiguration
                {
                    public:

                        CachedFileConfigurationBase( TM^ cfconfig ) : Base( cfconfig ) { }

                        CachedFileConfigurationBase( TN** const ppcfconfig ) : Base( ppcfconfig ) {}

                    public:

                        virtual bool IsCachingEnabled();

                        virtual String^ CachingFilePath();

                        virtual int BlockSize();

                        virtual int MaxConcurrentBlockWriteBacks();

                        virtual int CacheTelemetryFileNumber();
                };

                template< class TM, class TN, class TW >
                inline bool CachedFileConfigurationBase<TM, TN, TW>::IsCachingEnabled()
                {
                    return Pi->FCachingEnabled() ? true : false;
                }

                template< class TM, class TN, class TW >
                inline String^ CachedFileConfigurationBase<TM, TN, TW>::CachingFilePath()
                {
                    WCHAR   wszPath[ OSFSAPI_MAX_PATH ] = { 0 };

                    Pi->CachingFilePath( wszPath );

                    return gcnew String( wszPath );
                }

                template< class TM, class TN, class TW >
                inline int CachedFileConfigurationBase<TM, TN, TW>::BlockSize()
                {
                    return Pi->CbBlockSize();
                }

                template< class TM, class TN, class TW >
                inline int CachedFileConfigurationBase<TM, TN, TW>::MaxConcurrentBlockWriteBacks()
                {
                    return Pi->CConcurrentBlockWriteBackMax();
                }

                template< class TM, class TN, class TW >
                inline int CachedFileConfigurationBase<TM, TN, TW>::CacheTelemetryFileNumber()
                {
                    return Pi->LCacheTelemetryFileNumber();
                }
            }
        }
    }
}
