.setcpu "65816"
.segment "CODE"
.org $D1DD
map_control_0ed1dd:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
