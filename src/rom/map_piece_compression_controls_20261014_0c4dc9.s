.setcpu "65816"
.segment "CODE"
.org $4DC9
map_control_0c4dc9:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
