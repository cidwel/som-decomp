.setcpu "65816"
.segment "CODE"
.org $F506
map_control_0ff506:
    .byte $D3 ; same-value copy count/distance
