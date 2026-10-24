.setcpu "65816"
.segment "CODE"
.org $9C55
map_control_0d9c55:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
