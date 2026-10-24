.setcpu "65816"
.segment "CODE"
.org $AA94
map_control_0faa94:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
