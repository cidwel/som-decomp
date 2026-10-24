.setcpu "65816"
.segment "CODE"
.org $2B23
map_control_0c2b23:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
