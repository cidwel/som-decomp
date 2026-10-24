.setcpu "65816"
.segment "CODE"
.org $A66E
map_control_0fa66e:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
