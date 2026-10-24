.setcpu "65816"
.segment "CODE"
.org $9F30
map_control_0e9f30:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
