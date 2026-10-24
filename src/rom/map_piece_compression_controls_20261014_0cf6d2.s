.setcpu "65816"
.segment "CODE"
.org $F6D2
map_control_0cf6d2:
    .byte $F1 ; progressive-copy count
    .byte $E7 ; previous-row copy count
