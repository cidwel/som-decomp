.setcpu "65816"
.segment "CODE"
.org $F42F
map_control_0df42f:
    .byte $DF ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
