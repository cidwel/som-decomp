.setcpu "65816"
.segment "CODE"
.org $85D6
map_control_0c85d6:
    .byte $F1 ; progressive-copy count
    .byte $E5 ; previous-row copy count
