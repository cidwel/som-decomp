.setcpu "65816"
.segment "CODE"
.org $1952
map_control_0e1952:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
