.setcpu "65816"
.segment "CODE"
.org $755F
map_control_0e755f:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
