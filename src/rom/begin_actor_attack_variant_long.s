; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-attack-entry.md.
.setcpu "65816"
.smart
.a8
.i16

begin_actor_attack_variant_and_update_party_gauge = $B2A7

.segment "CODE"
.org $B295
begin_actor_attack_variant_long:
    phb
    .a8
    lda #$00
    pha
    plb
    jsr begin_actor_attack_variant_and_update_party_gauge
    plb
    rtl
