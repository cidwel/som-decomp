; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_eight_byte_record = $B1A9
allocate_ppu_register_entry = $C030
append_oneshot_ppu_entry = $C097
append_pending_record = $B258
copy_and_submit_title_tilemap = $CD82
current_task_parent_id = $ACD0
receive_with_supplied_delay = $ABE7

.segment "CODE"
.org $D0CC
run_title_control_task:
    phd
    php
    rep #$30
    sep #$20
    lda a:$0317
    bne run_title_control_task_d121
run_title_control_task_d0d7:
    .a8
    lda #$00
    jsr allocate_ppu_register_entry
    lda a:$0002,X
    beq run_title_control_task_d0f1
    dec a:$0002,X
    beq run_title_control_task_d0f1
    jsr append_oneshot_ppu_entry
    .i16
    ldx #$0001
    jsr receive_with_supplied_delay
    bra run_title_control_task_d0d7
run_title_control_task_d0f1:
    .i16
    ldx #$0000
    jsr copy_and_submit_title_tilemap
run_title_control_task_d0f7:
    .a8
    lda #$00
    jsr allocate_ppu_register_entry
    lda a:$0002,X
    .a8
    cmp #$0F
    beq run_title_control_task_d11b
    lda a:$0002,X
    inc
    sta a:$0002,X
    pha
    jsr append_oneshot_ppu_entry
    pla
    .a8
    cmp #$0F
    beq run_title_control_task_d11b
    .i16
    ldx #$0001
    jsr receive_with_supplied_delay
    bra run_title_control_task_d0f7
run_title_control_task_d11b:
    .i16
    ldx #$001E
    jsr receive_with_supplied_delay
run_title_control_task_d121:
    .a8
    lda #$00
    jsr allocate_ppu_register_entry
    lda a:$0002,X
    beq run_title_control_task_d13b
    dec a:$0002,X
    beq run_title_control_task_d13b
    jsr append_oneshot_ppu_entry
    .i16
    ldx #$0004
    jsr receive_with_supplied_delay
    bra run_title_control_task_d121
run_title_control_task_d13b:
    jsr append_oneshot_ppu_entry
    jsr current_task_parent_id
    pha
    jsr allocate_eight_byte_record
    pla
    jsr append_pending_record
    plp
    pld
    rtl
