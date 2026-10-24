.setcpu "65816"
.segment "CODE"
.org $EA07
map_control_0dea07:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
