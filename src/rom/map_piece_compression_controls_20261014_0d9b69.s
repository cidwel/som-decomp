.setcpu "65816"
.segment "CODE"
.org $9B69
map_control_0d9b69:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
