.setcpu "65816"
.segment "CODE"
.org $B800
map_control_0eb800:
    .byte $CB ; same-value copy count/distance
