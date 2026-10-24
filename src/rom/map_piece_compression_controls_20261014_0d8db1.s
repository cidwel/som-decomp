.setcpu "65816"
.segment "CODE"
.org $8DB1
map_control_0d8db1:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
