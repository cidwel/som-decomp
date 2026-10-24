.setcpu "65816"
.segment "CODE"
.org $3BD5
map_control_0c3bd5:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
