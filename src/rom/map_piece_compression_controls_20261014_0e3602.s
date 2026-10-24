.setcpu "65816"
.segment "CODE"
.org $3602
map_control_0e3602:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
