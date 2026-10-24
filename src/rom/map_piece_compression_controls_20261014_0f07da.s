.setcpu "65816"
.segment "CODE"
.org $07DA
map_control_0f07da:
    .byte $CB ; same-value copy count/distance
