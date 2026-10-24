.setcpu "65816"
.segment "CODE"
.org $8C1A
map_control_0c8c1a:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
