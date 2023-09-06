# Mortgage Payment Estimation Program

## Overview

Welcome to the Mortgage Payment Estimation Program! This software is designed to estimate the monthly mortgage payment for users based on their input. Additionally, the program will calculate and display the total amount paid, principal paid, and interest paid at the end of the loan term. Before we dive into using the program, let's understand its goals, inputs, and outputs.

## Program Goals

- Write, compile, and run your own program.
- Gain familiarity with the standard input/output library (iostream) to interact with users.
- Practice using data types, variables, and arithmetic operations.
- Learn common compiler error messages and how to fix them.

## Inputs

The program requires the following inputs from the user:

- Home price (in dollars)
- Down payment (in dollars)
- Length of the loan (in years)
- Annual interest rate (in percentage)

## Outputs

The program will provide the following outputs, all in dollars:

- Monthly mortgage payment
- Total amount paid
- Principal paid
- Interest paid

## Calculation Steps

The program follows these steps to estimate the monthly mortgage payment:

### Step 1: Determine the Mortgage Principal (P)

The mortgage principal is the initial loan amount borrowed to purchase the home. It's calculated by subtracting the down payment from the home price.

### Step 2: Calculate the Monthly Interest Rate (i)

The monthly interest rate is determined by dividing the annual interest rate by 12 (the number of months in a year).

### Step 3: Calculate the Number of Payments (n)

The number of monthly payments is calculated by multiplying the number of years of the mortgage by 12 (the number of months in a year).

### Equation for Monthly Mortgage Payment

The monthly mortgage payment (M) is calculated using the following formula:

M = P * [i(1 + i)^n] / [(1 + i)^n - 1]

Where:
- M = Monthly mortgage payment
- P = Mortgage principal loan amount
- i = Monthly interest rate
- n = Number of payments

## Using the Program

Now that you understand how the Mortgage Payment Estimation Program works, you can input the required information and get an estimate of your monthly mortgage payment, total amount paid, principal paid, and interest paid. It's a useful tool for anyone planning to own a home and needing to calculate their monthly expenses accurately.

Enjoy using the program and making informed financial decisions!
