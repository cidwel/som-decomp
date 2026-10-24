.setcpu "65816"
.segment "CODE"
.org $DCFA
map_control_0edcfa:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
