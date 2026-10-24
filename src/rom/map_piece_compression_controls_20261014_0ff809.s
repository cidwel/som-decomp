.setcpu "65816"
.segment "CODE"
.org $F809
map_control_0ff809:
    .byte $D9 ; same-value copy count/distance
