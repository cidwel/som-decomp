.setcpu "65816"
.segment "CODE"
.org $3919
map_control_0d3919:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
