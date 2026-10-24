.setcpu "65816"
.segment "CODE"
.org $173D
map_control_0e173d:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
