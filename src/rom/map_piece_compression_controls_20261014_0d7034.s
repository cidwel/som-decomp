.setcpu "65816"
.segment "CODE"
.org $7034
map_control_0d7034:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
