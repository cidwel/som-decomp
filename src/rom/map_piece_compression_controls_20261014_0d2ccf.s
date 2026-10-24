.setcpu "65816"
.segment "CODE"
.org $2CCF
map_control_0d2ccf:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
