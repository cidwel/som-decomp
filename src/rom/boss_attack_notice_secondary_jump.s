; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-status-child.md.
.setcpu "65816"
.smart
.a8
.i16

enqueue_numeric_boss_attack_notice_preserving_context = $5BCA

.segment "CODE"
.org $380F
boss_attack_notice_secondary_jump:
    jmp enqueue_numeric_boss_attack_notice_preserving_context
