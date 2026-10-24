; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-map-door-controller.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_destination_fade = $8B09

.segment "CODE"
.org $BA8B
request_diagonal_hero_door_motion_and_black_fade:
    sta $E1
    pha
    .a8
    lda #$18
    sta f:$7EE00A,X
    lda $E0
    .a8
    and #$E0
    .a8
    ora #$1F
    sta $E0
    pla
    .i16
    ldy #$8200
    .a8
    cmp #$0B
    beq request_diagonal_hero_door_motion_and_black_fade_c0bac3
    .i16
    ldy #$0200
    .a8
    cmp #$0C
    beq request_diagonal_hero_door_motion_and_black_fade_c0bac3
    .i16
    ldy #$0282
    .a8
    cmp #$0D
    beq request_diagonal_hero_door_motion_and_black_fade_c0bac3
    .i16
    ldy #$8202
    .a8
    cmp #$0E
    beq request_diagonal_hero_door_motion_and_black_fade_c0bac3
    .i16
    ldy #$0202
    .a8
    cmp #$0F
    beq request_diagonal_hero_door_motion_and_black_fade_c0bac3
    .i16
    ldy #$8282
request_diagonal_hero_door_motion_and_black_fade_c0bac3:
    rep #$20
    tya
    sta f:$7EE006
    sta f:$7EE206
    sta f:$7EE406
    jmp prepare_destination_fade
