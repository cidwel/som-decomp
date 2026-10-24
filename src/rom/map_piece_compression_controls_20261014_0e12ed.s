.setcpu "65816"
.segment "CODE"
.org $12ED
map_control_0e12ed:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
