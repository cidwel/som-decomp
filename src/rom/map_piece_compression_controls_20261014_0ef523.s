.setcpu "65816"
.segment "CODE"
.org $F523
map_control_0ef523:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
