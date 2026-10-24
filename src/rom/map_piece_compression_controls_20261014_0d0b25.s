.setcpu "65816"
.segment "CODE"
.org $0B25
map_control_0d0b25:
    .byte $C1 ; same-value copy count/distance
    .byte $DF ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
