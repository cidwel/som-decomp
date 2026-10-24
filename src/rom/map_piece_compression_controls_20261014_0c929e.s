.setcpu "65816"
.segment "CODE"
.org $929E
map_control_0c929e:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
