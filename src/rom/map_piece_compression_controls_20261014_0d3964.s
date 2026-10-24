.setcpu "65816"
.segment "CODE"
.org $3964
map_control_0d3964:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
