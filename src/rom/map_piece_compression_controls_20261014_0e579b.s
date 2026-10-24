.setcpu "65816"
.segment "CODE"
.org $579B
map_control_0e579b:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
