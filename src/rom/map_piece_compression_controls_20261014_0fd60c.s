.setcpu "65816"
.segment "CODE"
.org $D60C
map_control_0fd60c:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
