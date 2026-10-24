.setcpu "65816"
.segment "CODE"
.org $B248
map_control_0fb248:
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
