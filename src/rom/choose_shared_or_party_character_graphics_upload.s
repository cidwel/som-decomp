; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-constructor.md.
.setcpu "65816"
.smart
.a8
.i16

load_party_scene_frames_with_saved_data_bank = $FB01

.segment "CODE"
.org $F8A7
choose_shared_or_party_character_graphics_upload:
    sep #$30
    .a8
    lda #$03
    sta a:$2101
    lda $8C
    beq choose_shared_or_party_character_graphics_upload_c1f8bb
    lda $E3
    .a8
    and #$0F
    bne choose_shared_or_party_character_graphics_upload_c1f8bb
    jmp load_party_scene_frames_with_saved_data_bank
choose_shared_or_party_character_graphics_upload_c1f8bb:
    .a8
    lda #$80
    sta a:$2115
    .a8
    lda #$00
    sta a:$2116
    .a8
    lda #$60
    sta a:$2117
    .i8
    ldx #$00
choose_shared_or_party_character_graphics_upload_c1f8cc:
    lda f:$01F8DE,X
    sta a:$4370,X
    inx
    .i8
    cpx #$07
    bcc choose_shared_or_party_character_graphics_upload_c1f8cc
    .a8
    lda #$80
    sta a:$420B
    rts
