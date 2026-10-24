.setcpu "65816"
.segment "CODE"
.org $B4F1
map_control_0db4f1:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
