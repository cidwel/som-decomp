.setcpu "65816"
.segment "CODE"
.org $84BA
map_control_0e84ba:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
