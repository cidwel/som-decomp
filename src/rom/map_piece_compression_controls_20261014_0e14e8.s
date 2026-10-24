.setcpu "65816"
.segment "CODE"
.org $14E8
map_control_0e14e8:
    .byte $EB ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $28 ; distance low bit/count
