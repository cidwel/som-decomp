.setcpu "65816"
.segment "CODE"
.org $2B49
map_control_0f2b49:
    .byte $D7 ; same-value copy count/distance
    .byte $C5 ; same-value copy count/distance
