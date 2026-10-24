.setcpu "65816"
.segment "CODE"
.org $689C
map_control_0f689c:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
