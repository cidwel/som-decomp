.setcpu "65816"
.segment "CODE"
.org $5793
map_control_0d5793:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
