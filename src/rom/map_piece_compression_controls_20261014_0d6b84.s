.setcpu "65816"
.segment "CODE"
.org $6B84
map_control_0d6b84:
    .byte $E7 ; previous-row copy count
    .byte $F2 ; progressive-copy count
