.setcpu "65816"
.segment "CODE"
.org $3EB8
map_control_0e3eb8:
    .byte $F1 ; progressive-copy count
    .byte $E6 ; previous-row copy count
