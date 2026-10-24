.setcpu "65816"
.segment "CODE"
.org $4472
map_control_0e4472:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
