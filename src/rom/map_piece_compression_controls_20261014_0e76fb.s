.setcpu "65816"
.segment "CODE"
.org $76FB
map_control_0e76fb:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
