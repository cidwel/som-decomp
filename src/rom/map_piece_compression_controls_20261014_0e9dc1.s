.setcpu "65816"
.segment "CODE"
.org $9DC1
map_control_0e9dc1:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
