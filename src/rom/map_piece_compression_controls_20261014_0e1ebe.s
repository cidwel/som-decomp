.setcpu "65816"
.segment "CODE"
.org $1EBE
map_control_0e1ebe:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
