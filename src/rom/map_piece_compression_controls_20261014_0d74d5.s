.setcpu "65816"
.segment "CODE"
.org $74D5
map_control_0d74d5:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
