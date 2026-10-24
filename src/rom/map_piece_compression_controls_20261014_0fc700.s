.setcpu "65816"
.segment "CODE"
.org $C700
map_control_0fc700:
    .byte $C3 ; same-value copy count/distance
