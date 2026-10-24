; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_ppu_register_entry = $C030
append_oneshot_ppu_entry = $C097
release_transfer_descriptor = $9066
request_task_stop_by_id = $ACAC

.segment "CODE"
.org $D3AA
teardown_title_window_and_tracked_tasks:
    phd
    php
    rep #$30
    phb
    tsc
    tcd
    sep #$20
    ldx a:$030E
    jsr release_transfer_descriptor
    stz a:$030E
    stz a:$030F
    .a8
    lda #$2C
    jsr allocate_ppu_register_entry
    lda a:$0002,X
    .a8
    and #$FE
    sta a:$0002,X
    jsr append_oneshot_ppu_entry
    .a8
    lda #$14
    sta $01
    .i16
    ldx #$0318
teardown_title_window_and_tracked_tasks_d3d6:
    phx
    lda a:$0000,X
    jsr request_task_stop_by_id
    plx
    stz a:$0000,X
    inx
    dec $01
    bne teardown_title_window_and_tracked_tasks_d3d6
    pla
    plp
    pld
    rts
