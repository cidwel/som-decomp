.setcpu "65816"
.segment "CODE"
.org $F6B1
map_control_0ef6b1:
    .byte $DF ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
