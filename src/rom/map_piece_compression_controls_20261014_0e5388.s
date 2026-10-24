.setcpu "65816"
.segment "CODE"
.org $5388
map_control_0e5388:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
