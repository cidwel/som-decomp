.setcpu "65816"
.segment "CODE"
.org $7D50
map_control_0d7d50:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
