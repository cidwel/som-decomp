.setcpu "65816"
.segment "CODE"
.org $F925
map_control_0ef925:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
