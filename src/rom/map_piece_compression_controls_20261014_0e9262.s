.setcpu "65816"
.segment "CODE"
.org $9262
map_control_0e9262:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
