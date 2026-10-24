.setcpu "65816"
.segment "CODE"
.org $92DD
map_control_0c92dd:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
