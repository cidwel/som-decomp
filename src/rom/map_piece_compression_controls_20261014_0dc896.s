.setcpu "65816"
.segment "CODE"
.org $C896
map_control_0dc896:
    .byte $E8 ; backreference distance high bits
    .byte $76 ; distance low bit/count
