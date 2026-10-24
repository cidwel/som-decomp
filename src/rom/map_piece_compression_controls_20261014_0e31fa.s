.setcpu "65816"
.segment "CODE"
.org $31FA
map_control_0e31fa:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
