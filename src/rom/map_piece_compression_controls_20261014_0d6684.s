.setcpu "65816"
.segment "CODE"
.org $6684
map_control_0d6684:
    .byte $EF ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $2C ; distance low bit/count
