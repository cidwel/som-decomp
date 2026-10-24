.setcpu "65816"
.segment "CODE"
.org $8CCA
map_control_0d8cca:
    .byte $F3 ; progressive-copy count
    .byte $E2 ; previous-row copy count
