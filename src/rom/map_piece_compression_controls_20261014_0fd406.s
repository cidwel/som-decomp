.setcpu "65816"
.segment "CODE"
.org $D406
map_control_0fd406:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
