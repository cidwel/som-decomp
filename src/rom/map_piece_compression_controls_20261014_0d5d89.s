.setcpu "65816"
.segment "CODE"
.org $5D89
map_control_0d5d89:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
