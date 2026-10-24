.setcpu "65816"
.segment "CODE"
.org $43C3
map_control_0c43c3:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
