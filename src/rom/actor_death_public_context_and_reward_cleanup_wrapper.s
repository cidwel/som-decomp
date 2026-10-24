; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-public-death.md.
.setcpu "65816"
.smart
.a8
.i16

clear_map_entry_party_effects = $C05D46
prepare_cast_actor_context = $3962
routine_c04247 = $4247

.segment "CODE"
.org $4177
actor_death_public_context_and_reward_cleanup_wrapper:
    phd
    phb
    php
    rep #$30
    txy
    jsr prepare_cast_actor_context
    jsl f:clear_map_entry_party_effects
    ldx $85
    jsr routine_c04247
    lda $80
    .a8
    and #$7F
    sta $80
    stz a:$E059
    stz a:$E259
    stz a:$E459
    plp
    plb
    pld
    rtl
