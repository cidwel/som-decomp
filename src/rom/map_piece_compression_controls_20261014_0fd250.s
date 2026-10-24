.setcpu "65816"
.segment "CODE"
.org $D250
map_control_0fd250:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
