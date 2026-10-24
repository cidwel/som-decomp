.setcpu "65816"
.segment "CODE"
.org $ABD2
map_control_0dabd2:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
