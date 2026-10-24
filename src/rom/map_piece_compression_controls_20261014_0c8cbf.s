.setcpu "65816"
.segment "CODE"
.org $8CBF
map_control_0c8cbf:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
