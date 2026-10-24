.setcpu "65816"
.segment "CODE"
.org $8ED0
map_control_0f8ed0:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
