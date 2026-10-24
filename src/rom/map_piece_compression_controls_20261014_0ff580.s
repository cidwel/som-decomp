.setcpu "65816"
.segment "CODE"
.org $F580
map_control_0ff580:
    .byte $C1 ; same-value copy count/distance
