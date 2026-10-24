.setcpu "65816"
.segment "CODE"
.org $835F
map_control_0c835f:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
