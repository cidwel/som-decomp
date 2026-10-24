.setcpu "65816"
.segment "CODE"
.org $F03D
map_control_0df03d:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
