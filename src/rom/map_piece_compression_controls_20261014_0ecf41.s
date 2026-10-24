.setcpu "65816"
.segment "CODE"
.org $CF41
map_control_0ecf41:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
