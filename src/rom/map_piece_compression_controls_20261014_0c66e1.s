.setcpu "65816"
.segment "CODE"
.org $66E1
map_control_0c66e1:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
