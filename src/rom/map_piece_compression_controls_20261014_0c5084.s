.setcpu "65816"
.segment "CODE"
.org $5084
map_control_0c5084:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
