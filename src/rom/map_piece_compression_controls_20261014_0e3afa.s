.setcpu "65816"
.segment "CODE"
.org $3AFA
map_control_0e3afa:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
