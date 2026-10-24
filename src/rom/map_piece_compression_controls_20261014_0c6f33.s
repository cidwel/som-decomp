.setcpu "65816"
.segment "CODE"
.org $6F33
map_control_0c6f33:
    .byte $E2 ; previous-row copy count
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
