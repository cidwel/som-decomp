.setcpu "65816"
.segment "CODE"
.org $F781
map_control_0df781:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
