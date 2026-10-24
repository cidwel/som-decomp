.setcpu "65816"
.segment "CODE"
.org $E459
map_control_0fe459:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
