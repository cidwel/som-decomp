; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-public-pool-update.md.
.setcpu "65816"
.smart
.a8
.i16

update_boss_pool_then_consume_pending_cast_preserving_context = $01F9

.segment "CODE"
.org $0003
public_boss_pool_update_jump:
    jmp update_boss_pool_then_consume_pending_cast_preserving_context
