; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-rows.md.
.setcpu "65816"
.smart
.a8
.i16

update_native_menu_ring_row_angle_project_coordinates_and_publish_oam = $6D74

.segment "CODE"
.org $6D1C
project_and_publish_all_native_menu_ring_rows:
    rep #$30
    .i16
    ldx #$18C0
    lda a:$180B
    .a16
    and #$00FF
project_and_publish_all_native_menu_ring_rows_c06d27:
    pha
    phx
    jsr update_native_menu_ring_row_angle_project_coordinates_and_publish_oam
    pla
    clc
    .a16
    adc #$0010
    tax
    pla
    dec
    bne project_and_publish_all_native_menu_ring_rows_c06d27
    rts
