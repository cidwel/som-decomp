.setcpu "65816"
.segment "CODE"
.org $91B6
map_control_0c91b6:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
