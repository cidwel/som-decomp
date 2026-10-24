.setcpu "65816"
.segment "CODE"
.org $8DFA
map_control_0d8dfa:
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
