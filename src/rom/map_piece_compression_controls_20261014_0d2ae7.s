.setcpu "65816"
.segment "CODE"
.org $2AE7
map_control_0d2ae7:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
