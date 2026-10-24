.setcpu "65816"
.segment "CODE"
.org $9B23
map_control_0e9b23:
    .byte $E0 ; previous-row copy escape
    .byte $AA ; row-distance/count
