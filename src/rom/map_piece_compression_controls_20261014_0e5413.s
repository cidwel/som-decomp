.setcpu "65816"
.segment "CODE"
.org $5413
map_control_0e5413:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
