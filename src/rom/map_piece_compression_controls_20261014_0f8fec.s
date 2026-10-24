.setcpu "65816"
.segment "CODE"
.org $8FEC
map_control_0f8fec:
    .byte $D7 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
