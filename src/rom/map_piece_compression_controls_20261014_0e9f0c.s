.setcpu "65816"
.segment "CODE"
.org $9F0C
map_control_0e9f0c:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
