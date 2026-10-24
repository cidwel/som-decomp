.setcpu "65816"
.segment "CODE"
.org $93AD
map_control_0d93ad:
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
