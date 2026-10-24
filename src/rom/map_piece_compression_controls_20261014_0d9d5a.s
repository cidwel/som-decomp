.setcpu "65816"
.segment "CODE"
.org $9D5A
map_control_0d9d5a:
    .byte $EF ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
