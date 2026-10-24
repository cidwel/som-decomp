.setcpu "65816"
.segment "CODE"
.org $54CA
map_control_0e54ca:
    .byte $F1 ; progressive-copy count
    .byte $E5 ; previous-row copy count
