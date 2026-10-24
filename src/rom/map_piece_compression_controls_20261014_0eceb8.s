.setcpu "65816"
.segment "CODE"
.org $CEB8
map_control_0eceb8:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
