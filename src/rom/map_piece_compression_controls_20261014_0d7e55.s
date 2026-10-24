.setcpu "65816"
.segment "CODE"
.org $7E55
map_control_0d7e55:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $0E ; distance low bit/count
