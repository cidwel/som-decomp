.setcpu "65816"
.segment "CODE"
.org $C0CC
map_control_0fc0cc:
    .byte $D7 ; same-value copy count/distance
