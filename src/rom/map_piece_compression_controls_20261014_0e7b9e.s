.setcpu "65816"
.segment "CODE"
.org $7B9E
map_control_0e7b9e:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
