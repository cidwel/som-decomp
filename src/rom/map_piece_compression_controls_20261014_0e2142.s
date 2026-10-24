.setcpu "65816"
.segment "CODE"
.org $2142
map_control_0e2142:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
