.setcpu "65816"
.segment "CODE"
.org $7685
map_control_0e7685:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
