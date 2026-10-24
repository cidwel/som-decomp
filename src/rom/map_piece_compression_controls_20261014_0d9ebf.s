.setcpu "65816"
.segment "CODE"
.org $9EBF
map_control_0d9ebf:
    .byte $E0 ; previous-row copy escape
    .byte $3C ; row-distance/count
