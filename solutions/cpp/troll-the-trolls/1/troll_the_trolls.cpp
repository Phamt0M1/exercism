namespace hellmath {

    enum class AccountStatus {
        troll,
        guest,
        user,
        mod
    };

    enum class Action {
        read,
        write,
        remove
    };

    bool display_post(const AccountStatus poster, const AccountStatus viewer) {
        if (viewer != AccountStatus::troll && poster == AccountStatus::troll) {
            return false;
        }
        return true;
    }

    bool permission_check(const Action action, const AccountStatus status) {
        switch (status) {
            case AccountStatus::user:
            case AccountStatus::troll:
                if (action == Action::remove) {
                    return false;
                }
                return true;
            case AccountStatus::mod:
                return true;
            default :
                if (action == Action::read) {
                    return true;
                }
                return false;
        }
    }

    bool valid_player_combination(const AccountStatus player_1, const AccountStatus player_2) {
        if (player_1 == AccountStatus::guest || player_2 == AccountStatus::guest) {
            return false;
        }
        if (player_1 == AccountStatus::troll && player_2 == AccountStatus::troll) {
            return true;
        }
        if (player_1 != AccountStatus::troll && player_2 != AccountStatus::troll) {
            return true;
        }
        return false;
    }

    bool has_priority(const AccountStatus user_1, const AccountStatus user_2) {
        return static_cast<int>(user_1) > static_cast<int>(user_2);
    }

}  // namespace hellmath
