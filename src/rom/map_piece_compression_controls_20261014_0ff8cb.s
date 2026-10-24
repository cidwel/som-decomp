.setcpu "65816"
.segment "CODE"
.org $F8CB
map_control_0ff8cb:
    .byte $DA ; same-value copy count/distance
