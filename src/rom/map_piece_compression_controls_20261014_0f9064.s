.setcpu "65816"
.segment "CODE"
.org $9064
map_control_0f9064:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
