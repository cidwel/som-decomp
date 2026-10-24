.setcpu "65816"
.segment "CODE"
.org $0627
map_control_0f0627:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
