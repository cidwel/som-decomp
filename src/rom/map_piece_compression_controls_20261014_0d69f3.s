.setcpu "65816"
.segment "CODE"
.org $69F3
map_control_0d69f3:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
