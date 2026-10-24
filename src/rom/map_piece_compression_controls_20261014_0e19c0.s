.setcpu "65816"
.segment "CODE"
.org $19C0
map_control_0e19c0:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
