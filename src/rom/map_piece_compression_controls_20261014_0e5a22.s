.setcpu "65816"
.segment "CODE"
.org $5A22
map_control_0e5a22:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
