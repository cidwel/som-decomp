.setcpu "65816"
.segment "CODE"
.org $C80F
map_control_0ec80f:
    .byte $E2 ; previous-row copy count
