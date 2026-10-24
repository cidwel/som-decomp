.setcpu "65816"
.segment "CODE"
.org $9678
map_control_0d9678:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
