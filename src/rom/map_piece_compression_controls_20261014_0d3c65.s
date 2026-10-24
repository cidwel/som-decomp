.setcpu "65816"
.segment "CODE"
.org $3C65
map_control_0d3c65:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
