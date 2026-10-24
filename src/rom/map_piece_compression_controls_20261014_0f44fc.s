.setcpu "65816"
.segment "CODE"
.org $44FC
map_control_0f44fc:
    .byte $C4 ; same-value copy count/distance
