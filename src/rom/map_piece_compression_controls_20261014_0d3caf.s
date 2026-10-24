.setcpu "65816"
.segment "CODE"
.org $3CAF
map_control_0d3caf:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
