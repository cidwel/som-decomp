.setcpu "65816"
.segment "CODE"
.org $D080
map_control_0ed080:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
