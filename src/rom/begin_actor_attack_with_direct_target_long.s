; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-attack-entry.md.
.setcpu "65816"
.smart
.a8
.i16

begin_actor_attack_unless_movement_or_attack_busy = $B24A

.segment "CODE"
.org $B287
begin_actor_attack_with_direct_target_long:
    .a8
    lda #$FF
    sta $00
    phb
    .a8
    lda #$00
    pha
    plb
    jsr begin_actor_attack_unless_movement_or_attack_busy
    plb
    rtl
