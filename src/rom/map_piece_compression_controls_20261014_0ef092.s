.setcpu "65816"
.segment "CODE"
.org $F092
map_control_0ef092:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
