.setcpu "65816"
.segment "CODE"
.org $4AE4
map_control_0c4ae4:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
