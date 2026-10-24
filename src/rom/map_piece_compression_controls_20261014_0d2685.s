.setcpu "65816"
.segment "CODE"
.org $2685
map_control_0d2685:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
