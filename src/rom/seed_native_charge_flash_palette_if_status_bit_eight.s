; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-charge-gauge-presentation.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c1ca49 = $CA49

.segment "CODE"
.org $C9F1
seed_native_charge_flash_palette_if_status_bit_eight:
    lda a:$E100,X
    .a8
    bit #$08
    bne seed_native_charge_flash_palette_if_status_bit_eight_c1c9f9
    rtl
seed_native_charge_flash_palette_if_status_bit_eight_c1c9f9:
    .a8
    lda #$8D
    sta $0C
    .a8
    lda #$08
    sta a:$E100,X
    bra routine_c1ca49
