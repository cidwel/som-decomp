.setcpu "65816"
.segment "CODE"
.org $C272
map_control_0ec272:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
