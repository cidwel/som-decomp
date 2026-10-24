.setcpu "65816"
.segment "CODE"
.org $0076
map_control_0e0076:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
