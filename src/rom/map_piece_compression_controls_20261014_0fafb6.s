.setcpu "65816"
.segment "CODE"
.org $AFB6
map_control_0fafb6:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
