; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-point-layout.md.
.setcpu "65816"
.smart
.a8
.i16

append_or_retire_native_visual_effect_trail_points = $ACAC

.segment "CODE"
.org $ABCA
decode_and_publish_native_packed_visual_effect_trail:
    sep #$20
    .a8
    lda #$0A
    sta $04
    rep #$20
    lda [$10]
    inc $10
    .a16
    and #$003F
    sta a:$E114,X
    tay
    txa
    lsr
    tax
decode_and_publish_native_packed_visual_effect_trail_c2abe0:
    rep #$20
    lda [$10]
    inc $10
    inc $10
    sep #$20
    xba
    asl
    ror $01
    xba
    asl
    ror $01
    .a8
    cmp #$80
    bcc decode_and_publish_native_packed_visual_effect_trail_c2ac04
    bit $05
    bvs decode_and_publish_native_packed_visual_effect_trail_c2abfb
    ror
decode_and_publish_native_packed_visual_effect_trail_c2abfb:
    clc
    adc $0B
    bit $02
    bmi decode_and_publish_native_packed_visual_effect_trail_c2ac10
    bpl decode_and_publish_native_packed_visual_effect_trail_c2ac15
decode_and_publish_native_packed_visual_effect_trail_c2ac04:
    bit $05
    bvs decode_and_publish_native_packed_visual_effect_trail_c2ac09
    lsr
decode_and_publish_native_packed_visual_effect_trail_c2ac09:
    clc
    adc $0B
    bit $02
    bpl decode_and_publish_native_packed_visual_effect_trail_c2ac15
decode_and_publish_native_packed_visual_effect_trail_c2ac10:
    clc
    .a8
    adc #$0F
    .a8
    eor #$FF
decode_and_publish_native_packed_visual_effect_trail_c2ac15:
    xba
    bpl decode_and_publish_native_packed_visual_effect_trail_c2ac27
    bit $05
    bvs decode_and_publish_native_packed_visual_effect_trail_c2ac1e
    sec
    ror
decode_and_publish_native_packed_visual_effect_trail_c2ac1e:
    clc
    adc $0A
    bit $02
    bvs decode_and_publish_native_packed_visual_effect_trail_c2ac33
    bvc decode_and_publish_native_packed_visual_effect_trail_c2ac38
decode_and_publish_native_packed_visual_effect_trail_c2ac27:
    bit $05
    bvs decode_and_publish_native_packed_visual_effect_trail_c2ac2c
    lsr
decode_and_publish_native_packed_visual_effect_trail_c2ac2c:
    clc
    adc $0A
    bit $02
    bvc decode_and_publish_native_packed_visual_effect_trail_c2ac38
decode_and_publish_native_packed_visual_effect_trail_c2ac33:
    clc
    .a8
    adc #$0F
    .a8
    eor #$FF
decode_and_publish_native_packed_visual_effect_trail_c2ac38:
    rep #$20
    sta a:$C000,X
    sep #$20
    lda $01
    eor $02
    .a8
    and #$C0
    ora $0D
    sta a:$C003,X
    lda $0C
    sta a:$C002,X
    clc
    .a8
    adc #$02
    .a8
    bit #$10
    beq decode_and_publish_native_packed_visual_effect_trail_c2ac5c
    .a8
    adc #$10
    bcc decode_and_publish_native_packed_visual_effect_trail_c2ac5c
    inc $0D
decode_and_publish_native_packed_visual_effect_trail_c2ac5c:
    sta $0C
    dec $04
    bne decode_and_publish_native_packed_visual_effect_trail_c2ac7a
    .a8
    lda #$0A
    sta $04
    rep #$20
    lda $0C
    sec
    .a16
    sbc #$0024
    .a16
    bit #$0010
    beq decode_and_publish_native_packed_visual_effect_trail_c2ac76
    .a16
    sbc #$0010
decode_and_publish_native_packed_visual_effect_trail_c2ac76:
    sta $0C
    sep #$20
decode_and_publish_native_packed_visual_effect_trail_c2ac7a:
    inx
    inx
    inx
    inx
    dey
    beq decode_and_publish_native_packed_visual_effect_trail_c2ac84
    brl decode_and_publish_native_packed_visual_effect_trail_c2abe0
decode_and_publish_native_packed_visual_effect_trail_c2ac84:
    ldx $14
    rep #$20
    sep #$20
    stz a:$E0C2,X
    stz a:$E0C3,X
    lda a:$E114,X
    sta a:$E117,X
    stz a:$E115,X
    stz a:$E116,X
    stz a:$E126,X
    .a8
    lda #$40
    sta a:$E114,X
    jsr append_or_retire_native_visual_effect_trail_points
    rtl
