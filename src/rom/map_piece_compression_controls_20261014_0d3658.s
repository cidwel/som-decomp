.setcpu "65816"
.segment "CODE"
.org $3658
map_control_0d3658:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
