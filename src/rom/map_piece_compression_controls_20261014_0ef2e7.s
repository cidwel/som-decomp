.setcpu "65816"
.segment "CODE"
.org $F2E7
map_control_0ef2e7:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
