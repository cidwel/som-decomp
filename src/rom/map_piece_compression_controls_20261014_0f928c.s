.setcpu "65816"
.segment "CODE"
.org $928C
map_control_0f928c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
