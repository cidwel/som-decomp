.setcpu "65816"
.segment "CODE"
.org $E528
map_control_0de528:
    .byte $EE ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
