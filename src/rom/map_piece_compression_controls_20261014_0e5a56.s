.setcpu "65816"
.segment "CODE"
.org $5A56
map_control_0e5a56:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
