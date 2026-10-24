.setcpu "65816"
.segment "CODE"
.org $5EF2
map_control_0d5ef2:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
