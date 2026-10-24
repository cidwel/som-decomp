.setcpu "65816"
.segment "CODE"
.org $D6DB
map_control_0dd6db:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
