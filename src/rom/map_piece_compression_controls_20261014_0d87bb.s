.setcpu "65816"
.segment "CODE"
.org $87BB
map_control_0d87bb:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
