; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-status-child.md.
.setcpu "65816"
.smart
.a8
.i16

boss_attack_notice_secondary_jump = $380F

.segment "CODE"
.org $0027
boss_attack_notice_public_jump:
    jmp boss_attack_notice_secondary_jump
