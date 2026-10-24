.setcpu "65816"
.segment "CODE"
.org $E611
map_control_0de611:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
