.setcpu "65816"
.segment "CODE"
.org $914B
map_control_0f914b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
