.setcpu "65816"
.segment "CODE"
.org $2BB7
map_control_0c2bb7:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
