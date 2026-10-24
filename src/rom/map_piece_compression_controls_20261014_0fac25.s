.setcpu "65816"
.segment "CODE"
.org $AC25
map_control_0fac25:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
