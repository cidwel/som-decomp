.setcpu "65816"
.segment "CODE"
.org $3AB9
map_control_0d3ab9:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
