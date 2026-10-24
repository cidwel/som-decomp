.setcpu "65816"
.segment "CODE"
.org $F86D
map_control_0ff86d:
    .byte $C4 ; same-value copy count/distance
