.setcpu "65816"
.segment "CODE"
.org $0CFA
map_control_0c0cfa:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
