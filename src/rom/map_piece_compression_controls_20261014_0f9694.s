.setcpu "65816"
.segment "CODE"
.org $9694
map_control_0f9694:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
