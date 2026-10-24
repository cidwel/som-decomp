.setcpu "65816"
.segment "CODE"
.org $DDF6
map_control_0dddf6:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
