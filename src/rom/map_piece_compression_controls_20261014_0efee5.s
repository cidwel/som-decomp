.setcpu "65816"
.segment "CODE"
.org $FEE5
map_control_0efee5:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
