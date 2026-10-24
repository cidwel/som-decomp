.setcpu "65816"
.segment "CODE"
.org $5602
map_control_0e5602:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
