.setcpu "65816"
.segment "CODE"
.org $B612
map_control_0eb612:
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
