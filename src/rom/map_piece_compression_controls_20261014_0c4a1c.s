.setcpu "65816"
.segment "CODE"
.org $4A1C
map_control_0c4a1c:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
