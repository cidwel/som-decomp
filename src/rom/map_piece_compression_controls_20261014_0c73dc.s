.setcpu "65816"
.segment "CODE"
.org $73DC
map_control_0c73dc:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
