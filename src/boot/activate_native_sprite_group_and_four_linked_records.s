; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-group-sprite-allocate.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00b72b = $B72B
routine_7eb671 = $B671

.segment "CODE"
.org $B6FF
activate_native_sprite_group_and_four_linked_records:
    lda $02
    jsr routine_7eb671
    .i16
    cpx #$0000
    beq routine_00b72b
    .a8
    lda #$01
    sta a:$0008,X
    lda $02
    sta a:$000B,X
    .a8
    lda #$04
    sta $01
activate_native_sprite_group_and_four_linked_records_b717:
    ldy a:$0000,X
    .a8
    lda #$01
    sta a:$0008,Y
    lda $02
    sta a:$000B,Y
    inx
    inx
    dec $01
    bne activate_native_sprite_group_and_four_linked_records_b717
    plx
