.setcpu "65816"
.segment "CODE"
.org $7630
map_control_0c7630:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
