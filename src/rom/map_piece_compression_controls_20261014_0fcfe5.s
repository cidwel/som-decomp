.setcpu "65816"
.segment "CODE"
.org $CFE5
map_control_0fcfe5:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
