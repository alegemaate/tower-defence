/**
 * @file money.h
 * @author Allan Legemaate (alegemaate@gmail.com)
 * @brief Money component
 * @version 0.1
 * @date 2023-10-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

class Money
{
  public:
    /**
     * @brief Construct a new Money component
     *
     * @param money Initial money value
     */
    explicit Money(int money) : money_(money)
    {
    }

    /**
     * @brief Add money to current value
     *
     * @param amount Amount to add
     */
    auto addMoney(int amount) -> void
    {
        money_ += amount;
    }

    /**
     * @brief Remove money from current value
     *
     * @param amount Amount to remove
     */
    auto removeMoney(int amount) -> void
    {
        money_ -= amount;
    }

    /**
     * @brief Get the current money value
     *
     * @return int Money
     */
    auto getMoney() const -> int
    {
        return money_;
    }

  private:
    /// @breif current monetary value
    int money_{0};
};