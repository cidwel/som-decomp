.setcpu "65816"
.segment "CODE"
.org $5674
map_control_0c5674:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
