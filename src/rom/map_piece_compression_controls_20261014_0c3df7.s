.setcpu "65816"
.segment "CODE"
.org $3DF7
map_control_0c3df7:
    .byte $E1 ; previous-row copy count
    .byte $F1 ; progressive-copy count
