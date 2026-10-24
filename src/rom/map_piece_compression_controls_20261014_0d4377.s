.setcpu "65816"
.segment "CODE"
.org $4377
map_control_0d4377:
    .byte $ED ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $F0 ; progressive-copy escape
    .byte $82 ; direction/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
