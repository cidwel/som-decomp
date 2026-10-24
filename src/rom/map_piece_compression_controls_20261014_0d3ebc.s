.setcpu "65816"
.segment "CODE"
.org $3EBC
map_control_0d3ebc:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
