.setcpu "65816"
.segment "CODE"
.org $B911
map_control_0eb911:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
