.setcpu "65816"
.segment "CODE"
.org $719B
map_control_0c719b:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
