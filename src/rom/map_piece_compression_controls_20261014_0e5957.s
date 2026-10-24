.setcpu "65816"
.segment "CODE"
.org $5957
map_control_0e5957:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
