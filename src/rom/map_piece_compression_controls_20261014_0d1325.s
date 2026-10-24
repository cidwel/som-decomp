.setcpu "65816"
.segment "CODE"
.org $1325
map_control_0d1325:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
