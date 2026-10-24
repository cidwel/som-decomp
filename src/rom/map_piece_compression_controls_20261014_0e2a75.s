.setcpu "65816"
.segment "CODE"
.org $2A75
map_control_0e2a75:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
