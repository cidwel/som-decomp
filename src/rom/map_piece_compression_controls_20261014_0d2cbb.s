.setcpu "65816"
.segment "CODE"
.org $2CBB
map_control_0d2cbb:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
