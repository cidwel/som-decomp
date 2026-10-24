.setcpu "65816"
.segment "CODE"
.org $F98C
map_control_0df98c:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
