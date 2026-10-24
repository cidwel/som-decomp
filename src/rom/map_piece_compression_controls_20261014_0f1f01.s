.setcpu "65816"
.segment "CODE"
.org $1F01
map_control_0f1f01:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
