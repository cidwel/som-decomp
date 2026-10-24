; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_eight_byte_record = $B1A9
append_pending_record = $B258
queue_colour_sample_palette = $8686
receive_raw_task_record = $B2FB
release_eight_byte_record = $B1DD
replace_colour_graphics_workspace = $BEDD

.segment "CODE"
.org $9FA4
request_image_row_and_replace_graphics:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0002
    tcd
    tcs
    lda $03,S
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    rep #$20
    sta $03
    stx $01
    jsr allocate_eight_byte_record
    .a16
    lda #$0003
    sta a:$0003,X
    lda $03
    sta a:$0004,X
    lda $01
    jsr append_pending_record
    jsr receive_raw_task_record
    lda a:$0003,X
    beq request_image_row_and_replace_graphics_9ffc
    phx
    jsr queue_colour_sample_palette
    lda $03
    asl
    php
    sei
    sep #$20
    xba
    .a8
    lda #$20
    rep #$20
    sta f:$004202
    pha
    pla
    lda f:$004216
    plp
    tax
    jsr replace_colour_graphics_workspace
    plx
request_image_row_and_replace_graphics_9ffc:
    jsr release_eight_byte_record
    plb
    sep #$20
    pla
    pla
    pla
    pla
    plp
    pld
    rts
