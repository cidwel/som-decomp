.setcpu "65816"
.segment "CODE"
.org $F4CA
map_control_0ff4ca:
    .byte $D4 ; same-value copy count/distance
