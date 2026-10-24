.setcpu "65816"
.segment "CODE"
.org $B013
map_control_0fb013:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
