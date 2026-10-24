.setcpu "65816"
.segment "CODE"
.org $2CBF
map_control_0e2cbf:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
