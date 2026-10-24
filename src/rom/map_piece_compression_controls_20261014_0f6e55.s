.setcpu "65816"
.segment "CODE"
.org $6E55
map_control_0f6e55:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
