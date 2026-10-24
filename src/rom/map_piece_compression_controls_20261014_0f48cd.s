.setcpu "65816"
.segment "CODE"
.org $48CD
map_control_0f48cd:
    .byte $C1 ; same-value copy count/distance
