; Recovered Secret of Mana USA routine; behaviour documented in docs/map-graphics-runtime-animation.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C026
advance_map_graphics_animation_record_by_motion_type:
    rep #$20
    .i8
    cpy #$02
    bcs advance_map_graphics_animation_record_by_motion_type_c1c047
advance_map_graphics_animation_record_by_motion_type_c1c02c:
    lda a:$8204,X
    clc
    .a16
    adc #$0020
    .a16
    and #$01E0
advance_map_graphics_animation_record_by_motion_type_c1c036:
    sta a:$8204,X
    clc
    adc a:$8202,X
    sta a:$820A,X
    lda a:$8206,X
    sta a:$820C,X
    rts
advance_map_graphics_animation_record_by_motion_type_c1c047:
    .i8
    cpy #$04
    bcs advance_map_graphics_animation_record_by_motion_type_c1c088
    lda a:$8204,X
    clc
    .a16
    adc #$0002
    pha
    .a16
    and #$0010
    sta $02
    pla
    adc $02
    .a16
    and #$00FF
    sta a:$8204,X
    pha
    adc a:$8202,X
    sta $02
    .i8
    ldy #$00
    lda ($02),Y
    sta a:$8302,X
    .i8
    ldy #$10
    lda ($02),Y
    sta a:$8306,X
    pla
    .a16
    and #$000F
    lsr
    clc
    adc a:$8206,X
    sta a:$8300,X
    .a16
    ora #$0008
    sta a:$8304,X
    rts
advance_map_graphics_animation_record_by_motion_type_c1c088:
    .i8
    cpy #$05
    bcs advance_map_graphics_animation_record_by_motion_type_c1c099
advance_map_graphics_animation_record_by_motion_type_c1c08c:
    lda a:$8204,X
    clc
    .a16
    adc #$0040
    .a16
    and #$03C0
    jmp advance_map_graphics_animation_record_by_motion_type_c1c036
advance_map_graphics_animation_record_by_motion_type_c1c099:
    .i8
    cpy #$06
    bcs advance_map_graphics_animation_record_by_motion_type_c1c09f
    bra advance_map_graphics_animation_record_by_motion_type_c1c08c
advance_map_graphics_animation_record_by_motion_type_c1c09f:
    .i8
    cpy #$08
    bcs advance_map_graphics_animation_record_by_motion_type_c1c0a6
    jmp advance_map_graphics_animation_record_by_motion_type_c1c02c
advance_map_graphics_animation_record_by_motion_type_c1c0a6:
    .i8
    cpy #$0A
    bcs advance_map_graphics_animation_record_by_motion_type_c1c0c5
    lda a:$8204,X
    clc
    .a16
    adc #$0040
    .a16
    and #$07C0
advance_map_graphics_animation_record_by_motion_type_c1c0b4:
    sta a:$8204,X
    clc
    adc a:$8202,X
    sta a:$820A,X
    lda a:$8206,X
    sta a:$820C,X
    rts
advance_map_graphics_animation_record_by_motion_type_c1c0c5:
    .i8
    cpy #$0C
    bcs advance_map_graphics_animation_record_by_motion_type_c1c125
    lda a:$8204,X
    clc
    .a16
    adc #$0002
    pha
    .a16
    and #$0010
    beq advance_map_graphics_animation_record_by_motion_type_c1c0d9
    .a16
    ora #$0020
advance_map_graphics_animation_record_by_motion_type_c1c0d9:
    sta $02
    pla
    adc $02
    .a16
    and #$03FF
advance_map_graphics_animation_record_by_motion_type_c1c0e1:
    sta a:$8204,X
    pha
    adc a:$8202,X
    sta $02
    .i8
    ldy #$00
    lda ($02),Y
    sta a:$8302,X
    .i8
    ldy #$10
    lda ($02),Y
    sta a:$8306,X
    .i8
    ldy #$20
    lda ($02),Y
    sta a:$830A,X
    .i8
    ldy #$30
    lda ($02),Y
    sta a:$830E,X
    pla
    .a16
    and #$000F
    lsr
    clc
    adc a:$8206,X
    sta a:$8300,X
    .a16
    ora #$0008
    sta a:$8304,X
    .a16
    eor #$0018
    sta a:$8308,X
    .a16
    ora #$0008
    sta a:$830C,X
    rts
advance_map_graphics_animation_record_by_motion_type_c1c125:
    .i8
    cpy #$0D
    bcs advance_map_graphics_animation_record_by_motion_type_c1c136
    lda a:$8204,X
    clc
    .a16
    adc #$0040
    .a16
    and #$00FF
    jmp advance_map_graphics_animation_record_by_motion_type_c1c0b4
advance_map_graphics_animation_record_by_motion_type_c1c136:
    .i8
    cpy #$0E
    bcs advance_map_graphics_animation_record_by_motion_type_c1c155
    lda a:$8204,X
    clc
    .a16
    adc #$0002
    pha
    .a16
    and #$0010
    beq advance_map_graphics_animation_record_by_motion_type_c1c14a
    .a16
    ora #$0020
advance_map_graphics_animation_record_by_motion_type_c1c14a:
    sta $02
    pla
    adc $02
    .a16
    and #$007F
    jmp advance_map_graphics_animation_record_by_motion_type_c1c0e1
advance_map_graphics_animation_record_by_motion_type_c1c155:
    lda a:$8204,X
    clc
    .a16
    adc #$0040
    .a16
    and #$03C0
    jmp advance_map_graphics_animation_record_by_motion_type_c1c0b4
