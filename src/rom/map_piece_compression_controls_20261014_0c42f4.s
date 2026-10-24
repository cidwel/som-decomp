.setcpu "65816"
.segment "CODE"
.org $42F4
map_control_0c42f4:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
