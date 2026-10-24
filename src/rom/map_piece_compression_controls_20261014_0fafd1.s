.setcpu "65816"
.segment "CODE"
.org $AFD1
map_control_0fafd1:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
