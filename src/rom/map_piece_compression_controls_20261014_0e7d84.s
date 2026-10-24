.setcpu "65816"
.segment "CODE"
.org $7D84
map_control_0e7d84:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
