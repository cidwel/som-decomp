.setcpu "65816"
.segment "CODE"
.org $A864
map_control_0da864:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
