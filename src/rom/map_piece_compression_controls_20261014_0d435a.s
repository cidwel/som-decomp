.setcpu "65816"
.segment "CODE"
.org $435A
map_control_0d435a:
    .byte $ED ; backreference distance high bits
    .byte $07 ; distance low bit/count
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
