.setcpu "65816"
.segment "CODE"
.org $C197
map_control_0ec197:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
