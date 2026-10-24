.setcpu "65816"
.segment "CODE"
.org $5AD8
map_control_0c5ad8:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
