.setcpu "65816"
.segment "CODE"
.org $929B
map_control_0f929b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
