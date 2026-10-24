.setcpu "65816"
.segment "CODE"
.org $290B
map_control_0e290b:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
