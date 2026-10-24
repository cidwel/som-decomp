.setcpu "65816"
.segment "CODE"
.org $7F35
map_control_0e7f35:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
