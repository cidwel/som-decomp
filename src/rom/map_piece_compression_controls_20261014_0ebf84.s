.setcpu "65816"
.segment "CODE"
.org $BF84
map_control_0ebf84:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
