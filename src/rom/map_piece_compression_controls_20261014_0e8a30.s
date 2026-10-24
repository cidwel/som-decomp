.setcpu "65816"
.segment "CODE"
.org $8A30
map_control_0e8a30:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
