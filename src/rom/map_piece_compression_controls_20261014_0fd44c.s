.setcpu "65816"
.segment "CODE"
.org $D44C
map_control_0fd44c:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
