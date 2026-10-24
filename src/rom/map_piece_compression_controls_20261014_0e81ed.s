.setcpu "65816"
.segment "CODE"
.org $81ED
map_control_0e81ed:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
