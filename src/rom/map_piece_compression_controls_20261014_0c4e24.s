.setcpu "65816"
.segment "CODE"
.org $4E24
map_control_0c4e24:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
