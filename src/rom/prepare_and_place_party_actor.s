; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

load_actor_map_graphics = $DFD3
load_actor_map_palette = $E022
routine_02a2e8 = $2A2E8

.segment "CODE"
.org $E06F
prepare_and_place_party_actor:
    jsr load_actor_map_palette
    jsr load_actor_map_graphics
    jsl f:routine_02a2e8
    sep #$20
    stz a:$E02F,X
    stz a:$E19B,X
    lda $E0
    bpl prepare_and_place_party_actor_c1e094
    asl
    asl
    rol
    rol
    .a8
    and #$03
    .a8
    cmp #$03
    bne prepare_and_place_party_actor_c1e091
    .a8
    lda #$82
prepare_and_place_party_actor_c1e091:
    sta a:$E010,X
prepare_and_place_party_actor_c1e094:
    sep #$20
    .a8
    lda #$01
    sta a:$E083,X
    .a8
    lda #$D2
    sta a:$E033,X
    lda $BF
    bit $E8
    bpl prepare_and_place_party_actor_c1e0a9
    lda a:$CD0A
prepare_and_place_party_actor_c1e0a9:
    .a8
    and #$80
    sta a:$E00B,X
    asl
    rep #$20
    lda $A8
    ldy $AA
    bcc prepare_and_place_party_actor_c1e0bb
    lda $AC
    ldy $AE
prepare_and_place_party_actor_c1e0bb:
    clc
    .a16
    adc #$0080
    cmp $C0
    bcc prepare_and_place_party_actor_c1e0c5
    sbc $C0
prepare_and_place_party_actor_c1e0c5:
    sta a:$E002,X
    tya
    clc
    .a16
    adc #$0072
    cmp $C2
    bcc prepare_and_place_party_actor_c1e0d3
    sbc $C2
prepare_and_place_party_actor_c1e0d3:
    sta a:$E004,X
    rts
