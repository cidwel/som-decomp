.setcpu "65816"
.segment "CODE"
.org $7421
map_control_0e7421:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
