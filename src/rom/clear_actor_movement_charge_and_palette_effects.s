; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

cancel_actor_charge_and_start_weapon_gauge = $CACD
restore_actor_effect_palettes_unless_deferred = $CAAC

.segment "CODE"
.org $CA6C
clear_actor_movement_charge_and_palette_effects:
    sep #$20
    bit $5C
    bpl clear_actor_movement_charge_and_palette_effects_c1ca7e
    .i16
    cpx #$0600
    bcc clear_actor_movement_charge_and_palette_effects_c1ca7e
    stz a:$E104,X
    stz a:$E100,X
    rts
clear_actor_movement_charge_and_palette_effects_c1ca7e:
    lda a:$E01C,X
    bpl clear_actor_movement_charge_and_palette_effects_c1ca86
    jsr cancel_actor_charge_and_start_weapon_gauge
clear_actor_movement_charge_and_palette_effects_c1ca86:
    lda a:$E01A,X
    ora a:$E01B,X
    beq clear_actor_movement_charge_and_palette_effects_c1ca91
    jsr cancel_actor_charge_and_start_weapon_gauge
clear_actor_movement_charge_and_palette_effects_c1ca91:
    jsr restore_actor_effect_palettes_unless_deferred
    stz a:$E008,X
    stz a:$E041,X
    stz a:$E006,X
    stz a:$E007,X
    stz a:$E013,X
    stz a:$E067,X
    .a8
    lda #$FF
    sta a:$E030,X
    rts
