.setcpu "65816"
.segment "CODE"
.org $444D
map_control_0c444d:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
