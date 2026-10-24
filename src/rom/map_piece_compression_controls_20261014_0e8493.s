.setcpu "65816"
.segment "CODE"
.org $8493
map_control_0e8493:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
