.setcpu "65816"
.segment "CODE"
.org $24A7
map_control_0e24a7:
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
