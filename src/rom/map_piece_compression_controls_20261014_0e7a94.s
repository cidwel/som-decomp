.setcpu "65816"
.segment "CODE"
.org $7A94
map_control_0e7a94:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
