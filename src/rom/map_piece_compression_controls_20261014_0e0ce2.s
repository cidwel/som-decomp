.setcpu "65816"
.segment "CODE"
.org $0CE2
map_control_0e0ce2:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
