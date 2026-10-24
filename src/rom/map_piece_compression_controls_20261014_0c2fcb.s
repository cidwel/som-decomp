.setcpu "65816"
.segment "CODE"
.org $2FCB
map_control_0c2fcb:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
