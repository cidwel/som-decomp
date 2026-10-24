.setcpu "65816"
.segment "CODE"
.org $DFA9
map_control_0edfa9:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
