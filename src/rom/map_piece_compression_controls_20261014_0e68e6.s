.setcpu "65816"
.segment "CODE"
.org $68E6
map_control_0e68e6:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
