.setcpu "65816"
.segment "CODE"
.org $F103
map_control_0cf103:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
