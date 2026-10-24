.setcpu "65816"
.segment "CODE"
.org $50C2
map_control_0e50c2:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
