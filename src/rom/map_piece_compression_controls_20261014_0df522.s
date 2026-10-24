.setcpu "65816"
.segment "CODE"
.org $F522
map_control_0df522:
    .byte $ED ; backreference distance high bits
    .byte $09 ; distance low bit/count
