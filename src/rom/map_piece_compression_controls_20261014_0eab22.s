.setcpu "65816"
.segment "CODE"
.org $AB22
map_control_0eab22:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
