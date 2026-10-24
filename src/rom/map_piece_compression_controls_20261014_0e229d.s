.setcpu "65816"
.segment "CODE"
.org $229D
map_control_0e229d:
    .byte $EB ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $50 ; distance low bit/count
