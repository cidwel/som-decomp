.setcpu "65816"
.segment "CODE"
.org $4E6C
map_control_0c4e6c:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
