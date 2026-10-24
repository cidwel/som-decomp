.setcpu "65816"
.segment "CODE"
.org $F49D
map_control_0df49d:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
