.setcpu "65816"
.segment "CODE"
.org $4674
map_control_0d4674:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
