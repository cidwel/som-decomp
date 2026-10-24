.setcpu "65816"
.segment "CODE"
.org $3C1E
map_control_0e3c1e:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
