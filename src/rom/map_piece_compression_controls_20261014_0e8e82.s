.setcpu "65816"
.segment "CODE"
.org $8E82
map_control_0e8e82:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
