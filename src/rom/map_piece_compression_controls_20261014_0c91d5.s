.setcpu "65816"
.segment "CODE"
.org $91D5
map_control_0c91d5:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
