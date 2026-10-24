.setcpu "65816"
.segment "CODE"
.org $F505
map_control_0df505:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
