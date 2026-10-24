.setcpu "65816"
.segment "CODE"
.org $909B
map_control_0e909b:
    .byte $E8 ; backreference distance high bits
    .byte $64 ; distance low bit/count
