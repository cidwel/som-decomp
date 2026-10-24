.setcpu "65816"
.segment "CODE"
.org $2883
map_control_0c2883:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
