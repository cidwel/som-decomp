.setcpu "65816"
.segment "CODE"
.org $8A7A
map_control_0c8a7a:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
