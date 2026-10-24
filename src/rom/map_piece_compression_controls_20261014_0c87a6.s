.setcpu "65816"
.segment "CODE"
.org $87A6
map_control_0c87a6:
    .byte $EE ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
