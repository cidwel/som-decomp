.setcpu "65816"
.segment "CODE"
.org $5A8D
map_control_0e5a8d:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
