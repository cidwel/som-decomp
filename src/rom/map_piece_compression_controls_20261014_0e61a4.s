.setcpu "65816"
.segment "CODE"
.org $61A4
map_control_0e61a4:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
