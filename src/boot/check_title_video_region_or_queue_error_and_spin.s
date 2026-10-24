; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-region-gate.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_ppu_register_entry = $C030
append_oneshot_ppu_entry = $C097
queue_registered_vram_buffer = $C870
render_three_native_region_error_rows = $8EA6

.segment "CODE"
.org $D445
check_title_video_region_or_queue_error_and_spin:
    phd
    php
    rep #$30
    sep #$20
    lda f:$00213F
    .a8
    and #$10
    .a8
    cmp #$00
    beq check_title_video_region_or_queue_error_and_spin_d470
    .a8
    lda #$00
    jsr allocate_ppu_register_entry
    .a8
    lda #$0F
    sta a:$0002,X
    jsr append_oneshot_ppu_entry
    ldx a:$0306
    jsr render_three_native_region_error_rows
    ldx a:$0306
    jsr queue_registered_vram_buffer
check_title_video_region_or_queue_error_and_spin_d46e:
    bra check_title_video_region_or_queue_error_and_spin_d46e
check_title_video_region_or_queue_error_and_spin_d470:
    plp
    pld
    rts
