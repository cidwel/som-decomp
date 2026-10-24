.setcpu "65816"
.segment "CODE"
.org $ACDC
map_control_0dacdc:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
