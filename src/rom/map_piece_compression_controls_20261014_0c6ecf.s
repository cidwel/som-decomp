.setcpu "65816"
.segment "CODE"
.org $6ECF
map_control_0c6ecf:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
