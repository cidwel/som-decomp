.setcpu "65816"
.segment "CODE"
.org $92ED
map_control_0d92ed:
    .byte $E8 ; backreference distance high bits
    .byte $4A ; distance low bit/count
