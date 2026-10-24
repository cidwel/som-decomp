.setcpu "65816"
.segment "CODE"
.org $F728
map_control_0df728:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
