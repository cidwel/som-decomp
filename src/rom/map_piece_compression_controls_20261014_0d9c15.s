.setcpu "65816"
.segment "CODE"
.org $9C15
map_control_0d9c15:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
