.setcpu "65816"
.segment "CODE"
.org $08C1
map_control_0f08c1:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
