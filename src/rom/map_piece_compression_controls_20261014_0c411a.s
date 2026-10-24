.setcpu "65816"
.segment "CODE"
.org $411A
map_control_0c411a:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
