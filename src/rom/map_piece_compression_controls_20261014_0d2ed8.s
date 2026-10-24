.setcpu "65816"
.segment "CODE"
.org $2ED8
map_control_0d2ed8:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
