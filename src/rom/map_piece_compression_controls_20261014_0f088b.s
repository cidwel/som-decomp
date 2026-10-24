.setcpu "65816"
.segment "CODE"
.org $088B
map_control_0f088b:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
