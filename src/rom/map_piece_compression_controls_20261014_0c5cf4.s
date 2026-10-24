.setcpu "65816"
.segment "CODE"
.org $5CF4
map_control_0c5cf4:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
