.setcpu "65816"
.segment "CODE"
.org $D0F1
map_control_0ed0f1:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
