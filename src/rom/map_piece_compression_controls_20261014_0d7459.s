.setcpu "65816"
.segment "CODE"
.org $7459
map_control_0d7459:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
