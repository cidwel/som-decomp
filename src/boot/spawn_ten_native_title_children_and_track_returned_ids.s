; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-tracked-children.md.
.setcpu "65816"
.smart
.a8
.i16

create_and_enqueue_task = $AB88

.segment "CODE"
.org $D051
spawn_ten_native_title_children_and_track_returned_ids:
    phd
    php
    rep #$30
    phb
    tsc
    tcd
    sep #$20
    .a8
    lda #$0A
    sta $01
    .i16
    ldx #$0318
spawn_ten_native_title_children_and_track_returned_ids_d061:
    phx
    .a8
    lda #$7E
    .i16
    ldx #$5F1C
    jsr create_and_enqueue_task
    plx
    xba
spawn_ten_native_title_children_and_track_returned_ids_d06c:
    lda a:$0000,X
    beq spawn_ten_native_title_children_and_track_returned_ids_d074
    inx
    bra spawn_ten_native_title_children_and_track_returned_ids_d06c
spawn_ten_native_title_children_and_track_returned_ids_d074:
    xba
    sta a:$0000,X
    inx
    dec $01
    bne spawn_ten_native_title_children_and_track_returned_ids_d061
    pla
    plp
    pld
    rts
