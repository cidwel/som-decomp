.setcpu "65816"
.segment "CODE"
.org $B076
map_control_0db076:
    .byte $C5 ; same-value copy count/distance
