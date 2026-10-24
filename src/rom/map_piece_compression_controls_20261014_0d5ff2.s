.setcpu "65816"
.segment "CODE"
.org $5FF2
map_control_0d5ff2:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
