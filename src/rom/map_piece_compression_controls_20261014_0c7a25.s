.setcpu "65816"
.segment "CODE"
.org $7A25
map_control_0c7a25:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
