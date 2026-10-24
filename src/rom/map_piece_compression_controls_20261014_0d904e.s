.setcpu "65816"
.segment "CODE"
.org $904E
map_control_0d904e:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
