.setcpu "65816"
.segment "CODE"
.org $2563
map_control_0d2563:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
