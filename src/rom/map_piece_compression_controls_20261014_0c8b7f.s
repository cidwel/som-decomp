.setcpu "65816"
.segment "CODE"
.org $8B7F
map_control_0c8b7f:
    .byte $F1 ; progressive-copy count
    .byte $E7 ; previous-row copy count
