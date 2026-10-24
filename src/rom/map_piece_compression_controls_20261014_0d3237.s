.setcpu "65816"
.segment "CODE"
.org $3237
map_control_0d3237:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
