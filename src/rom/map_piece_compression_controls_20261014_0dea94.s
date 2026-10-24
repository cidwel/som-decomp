.setcpu "65816"
.segment "CODE"
.org $EA94
map_control_0dea94:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
