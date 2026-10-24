.setcpu "65816"
.segment "CODE"
.org $FDF7
map_control_0dfdf7:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
