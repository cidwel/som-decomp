.setcpu "65816"
.segment "CODE"
.org $9DFA
map_control_0f9dfa:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
