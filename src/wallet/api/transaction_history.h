// Get last updates on http://flurbo.cc
//             ___ _  _ ____
//              |  |--| |===                      
//  _____ __    _____ _____ _____ _____
// |   __|  |  |  |  | __  | __  |     |
// |   __|  |__|  |  |    -| __ -|  |  |
// |__|  |_____|_____|__|__|_____|_____|
//   ___  ____ ____    _ ____ ____ ___
//   |--' |--< [__] ___| |=== |___  | 
//
// Based on "The Monero Project" and "Cryptonote Protocol".
//
// Copyright (c) 2018-.... The Flurbo developers.
// Copyright (c) 2014-2018 The Monero developers.
// Copyright (c) 2012-2013 The Cryptonote developers.
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


#include "wallet/api/wallet2_api.h"
#include <boost/thread/shared_mutex.hpp>

namespace Flurbo {

class WalletImpl;

class TransactionHistoryImpl : public TransactionHistory
{
public:
    TransactionHistoryImpl(WalletImpl * wallet);
    ~TransactionHistoryImpl();
    virtual int count() const;
    virtual TransactionInfo * transaction(int index)  const;
    virtual TransactionInfo * transaction(const std::string &id) const;
    virtual std::vector<TransactionInfo*> getAll() const;
    virtual void refresh();

private:

    // TransactionHistory is responsible of memory management
    std::vector<TransactionInfo*> m_history;
    WalletImpl *m_wallet;
    mutable boost::shared_mutex   m_historyMutex;
};

}

namespace Bitflurbo = Flurbo;

