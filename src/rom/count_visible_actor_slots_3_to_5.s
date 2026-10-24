; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

test_actor_on_screen = $0526

.segment "CODE"
.org $0D33
count_visible_actor_slots_3_to_5:
    phd
    php
    rep #$20
    phx
    tsc
    tcd
    sep #$20
    .a8
    lda #$03
    sta $01
    stz $02
    .i16
    ldx #$E600
count_visible_actor_slots_3_to_5_c10d45:
    jsr test_actor_on_screen
    bne count_visible_actor_slots_3_to_5_c10d4c
    inc $02
count_visible_actor_slots_3_to_5_c10d4c:
    clc
    rep #$20
    txa
    .a16
    adc #$0200
    tax
    sep #$20
    dec $01
    bne count_visible_actor_slots_3_to_5_c10d45
    lda $02
    sta $02,S
    pla
    pla
    plp
    pld
    rts
