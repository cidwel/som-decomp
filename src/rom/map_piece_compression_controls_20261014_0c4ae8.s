.setcpu "65816"
.segment "CODE"
.org $4AE8
map_control_0c4ae8:
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
