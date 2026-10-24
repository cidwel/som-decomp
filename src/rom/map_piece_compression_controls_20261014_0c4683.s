.setcpu "65816"
.segment "CODE"
.org $4683
map_control_0c4683:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
