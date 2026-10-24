.setcpu "65816"
.segment "CODE"
.org $9BF0
map_control_0f9bf0:
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
