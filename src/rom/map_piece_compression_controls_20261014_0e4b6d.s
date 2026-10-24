.setcpu "65816"
.segment "CODE"
.org $4B6D
map_control_0e4b6d:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
