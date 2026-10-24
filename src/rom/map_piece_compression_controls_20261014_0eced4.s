.setcpu "65816"
.segment "CODE"
.org $CED4
map_control_0eced4:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
