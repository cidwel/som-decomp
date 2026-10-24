.setcpu "65816"
.segment "CODE"
.org $7D4A
map_control_0c7d4a:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
