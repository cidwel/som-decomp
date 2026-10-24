.setcpu "65816"
.segment "CODE"
.org $5821
map_control_0e5821:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
