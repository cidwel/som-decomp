.setcpu "65816"
.segment "CODE"
.org $8F3A
map_control_0f8f3a:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
