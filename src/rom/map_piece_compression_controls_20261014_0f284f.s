.setcpu "65816"
.segment "CODE"
.org $284F
map_control_0f284f:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
