.setcpu "65816"
.segment "CODE"
.org $5A64
map_control_0d5a64:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
