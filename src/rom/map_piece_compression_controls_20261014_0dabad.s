.setcpu "65816"
.segment "CODE"
.org $ABAD
map_control_0dabad:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
