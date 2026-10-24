.setcpu "65816"
.segment "CODE"
.org $EE1C
map_control_0fee1c:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
