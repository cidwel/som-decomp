.setcpu "65816"
.segment "CODE"
.org $5DFA
map_control_0c5dfa:
    .byte $F2 ; progressive-copy count
    .byte $E3 ; previous-row copy count
    .byte $F3 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
