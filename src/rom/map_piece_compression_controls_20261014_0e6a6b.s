.setcpu "65816"
.segment "CODE"
.org $6A6B
map_control_0e6a6b:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
