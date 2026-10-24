.setcpu "65816"
.segment "CODE"
.org $CAF5
map_control_0dcaf5:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
