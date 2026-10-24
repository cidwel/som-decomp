; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_eight_byte_record = $B1A9
append_pending_record = $B258
build_colour_binary_tree = $A090
current_task_parent_id = $ACD0
decode_three_component_lanes = $83AD
generate_twelve_row_image = $A009
initialize_colour_decoder = $A12E
initialize_colour_lookup = $8621
prepare_colour_resources = $964B
queue_colour_sample_palette = $8686
receive_raw_task_record = $B2FB
release_colour_resources = $9660
release_eight_byte_record = $B1DD

.segment "CODE"
.org $968D
colour_image_task:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0005
    tcd
    tcs
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    jsr current_task_parent_id
    sta $03
    jsr prepare_colour_resources
    .i16
    ldx #$E536
    .a16
    lda #$00D2
    jsr build_colour_binary_tree
    sta $04
    xba
    .a16
    and #$00FF
    inc
    sta $01
    asl
    clc
    adc $01
    clc
    .a16
    adc #$E536
    tay
    .a16
    lda #$00D2
    .i16
    ldx #$0080
    jsr initialize_colour_decoder
    .i16
    ldy #$00E8
    jsr decode_three_component_lanes
    jsr initialize_colour_lookup
    jsr queue_colour_sample_palette
    jsr allocate_eight_byte_record
    .a16
    lda #$0002
    sta a:$0003,X
    lda $03
    jsr append_pending_record
    jsr receive_raw_task_record
    jsr release_eight_byte_record
    lda $03
    .i16
    ldx #$0080
    jsr generate_twelve_row_image
    jsr allocate_eight_byte_record
    .a16
    lda #$0004
    sta a:$0003,X
    lda $03
    jsr append_pending_record
    jsr receive_raw_task_record
    jsr release_eight_byte_record
    jsr release_colour_resources
    plb
    tsc
    clc
    .a16
    adc #$0005
    tcs
    plp
    pld
    rtl
