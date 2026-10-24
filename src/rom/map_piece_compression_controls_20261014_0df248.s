.setcpu "65816"
.segment "CODE"
.org $F248
map_control_0df248:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
