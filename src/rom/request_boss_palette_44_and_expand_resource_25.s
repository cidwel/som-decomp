; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-screen-requests.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_palette_transition_object = $272D
copy_boss_palette_with_cpu_words = $26F9
prepare_boss_loader_resource_expansion = $24C3

.segment "CODE"
.org $6F2E
request_boss_palette_44_and_expand_resource_25:
    .a16
    lda #$0044
    .i16
    ldx #$000D
    jsr copy_boss_palette_with_cpu_words
    sep #$20
    .a8
    lda #$44
    .i16
    ldx #$0006
    sta a:$033F,X
    .a8
    lda #$44
    inx
    sta a:$033F,X
    rep #$20
    .i16
    ldx #$0044
    .i16
    ldy #$0006
    .a16
    lda #$0036
    jsr allocate_boss_palette_transition_object
    .i16
    ldx #$003F
    .i16
    ldy #$0007
    .a16
    lda #$0036
    jsr allocate_boss_palette_transition_object
    .a16
    lda #$0025
    jsr prepare_boss_loader_resource_expansion
    rts
