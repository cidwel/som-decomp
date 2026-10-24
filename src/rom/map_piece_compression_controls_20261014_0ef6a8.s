.setcpu "65816"
.segment "CODE"
.org $F6A8
map_control_0ef6a8:
    .byte $DF ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
