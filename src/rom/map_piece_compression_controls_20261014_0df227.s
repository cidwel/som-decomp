.setcpu "65816"
.segment "CODE"
.org $F227
map_control_0df227:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
