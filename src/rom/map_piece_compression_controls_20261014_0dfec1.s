.setcpu "65816"
.segment "CODE"
.org $FEC1
map_control_0dfec1:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
