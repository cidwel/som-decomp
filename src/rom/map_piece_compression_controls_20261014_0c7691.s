.setcpu "65816"
.segment "CODE"
.org $7691
map_control_0c7691:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
