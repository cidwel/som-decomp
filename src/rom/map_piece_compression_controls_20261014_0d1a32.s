.setcpu "65816"
.segment "CODE"
.org $1A32
map_control_0d1a32:
    .byte $C1 ; same-value copy count/distance
    .byte $DF ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
