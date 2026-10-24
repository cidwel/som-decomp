.setcpu "65816"
.segment "CODE"
.org $5A37
map_control_0e5a37:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
