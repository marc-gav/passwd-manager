#pragma once
#ifndef PWFUNC_H
#define PWFUNC_H

#include "base.h"
#include "hash.h"

class PwFunc {
    /*
    this class provides methods that can be used to turn a password string u_int64_to a hash.
    Its using different chainhash methods.
    A chainhash is a hashfunction that is applied to the password and again to the result hash.
    This will loop for a given number of iterations. If you perform the same chainhash with the same password,
    you will get to the same hash.
    */
   private:
    const Hash* hash;  // stores the hash function that should be used
   public:
    // checks the password for illegal characters and length
    static ErrorStruct<bool> isPasswordValid(const std::string password) noexcept;

    PwFunc(const Hash* hash) noexcept;                                                           // sets the hash function
    Bytes chainhash(const std::string password, const u_int64_t iterations = 1) const noexcept;  // performs a chainhash
    // adds a constant salt each iteration
    Bytes chainhashWithConstantSalt(const std::string password, const u_int64_t iterations = 1, const std::string salt = "") const noexcept;
    // adds a salt (number that counts up each iteration)
    Bytes chainhashWithCountSalt(const std::string password, const u_int64_t iterations = 1, u_int64_t salt_start = 1) const noexcept;
    // adds a constant and count salt each iteration
    Bytes chainhashWithCountAndConstantSalt(const std::string password, const u_int64_t iterations = 1, u_int64_t salt_start = 1, const std::string salt = "") const noexcept;
    // adds a quadratic count salt each iteration
    Bytes chainhashWithQuadraticCountSalt(const std::string password, const u_int64_t iterations = 1, u_int64_t salt_start = 1, const u_int64_t a = 1, const u_int64_t b = 1,
                                          const u_int64_t c = 1) const noexcept;

    // overload with Bytes data
    Bytes chainhash(const Bytes data, const u_int64_t iterations = 1) const noexcept;  // performs a chainhash
    // adds a constant salt each iteration
    Bytes chainhashWithConstantSalt(const Bytes data, const u_int64_t iterations = 1, const std::string salt = "") const noexcept;
    // adds a salt (number that counts up each iteration)
    Bytes chainhashWithCountSalt(const Bytes data, const u_int64_t iterations = 1, u_int64_t salt_start = 1) const noexcept;
    // adds a constant and count salt each iteration
    Bytes chainhashWithCountAndConstantSalt(const Bytes data, const u_int64_t iterations = 1, u_int64_t salt_start = 1, const std::string salt = "") const noexcept;
    // adds a quadratic count salt each iteration
    Bytes chainhashWithQuadraticCountSalt(const Bytes data, const u_int64_t iterations = 1, u_int64_t salt_start = 1, const u_int64_t a = 1, const u_int64_t b = 1,
                                          const u_int64_t c = 1) const noexcept;
};

#endif  // PWFUNC_H