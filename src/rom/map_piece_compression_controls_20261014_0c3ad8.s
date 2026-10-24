.setcpu "65816"
.segment "CODE"
.org $3AD8
map_control_0c3ad8:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
