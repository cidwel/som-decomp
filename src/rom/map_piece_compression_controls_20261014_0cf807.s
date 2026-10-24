.setcpu "65816"
.segment "CODE"
.org $F807
map_control_0cf807:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
