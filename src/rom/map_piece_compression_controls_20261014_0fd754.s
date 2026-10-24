.setcpu "65816"
.segment "CODE"
.org $D754
map_control_0fd754:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
