.setcpu "65816"
.segment "CODE"
.org $921B
map_control_0c921b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
