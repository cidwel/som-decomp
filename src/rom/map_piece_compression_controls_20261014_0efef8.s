.setcpu "65816"
.segment "CODE"
.org $FEF8
map_control_0efef8:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
