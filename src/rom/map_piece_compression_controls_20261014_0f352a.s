.setcpu "65816"
.segment "CODE"
.org $352A
map_control_0f352a:
    .byte $D7 ; same-value copy count/distance
    .byte $C4 ; same-value copy count/distance
