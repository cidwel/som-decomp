.setcpu "65816"
.segment "CODE"
.org $2E26
map_control_0c2e26:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
