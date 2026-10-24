.setcpu "65816"
.segment "CODE"
.org $14EC
map_control_0f14ec:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
