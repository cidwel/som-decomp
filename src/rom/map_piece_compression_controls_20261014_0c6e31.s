.setcpu "65816"
.segment "CODE"
.org $6E31
map_control_0c6e31:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
