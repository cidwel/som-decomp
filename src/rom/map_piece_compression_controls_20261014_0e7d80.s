.setcpu "65816"
.segment "CODE"
.org $7D80
map_control_0e7d80:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
