.setcpu "65816"
.segment "CODE"
.org $8F11
map_control_0f8f11:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
