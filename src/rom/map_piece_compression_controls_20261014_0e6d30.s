.setcpu "65816"
.segment "CODE"
.org $6D30
map_control_0e6d30:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
