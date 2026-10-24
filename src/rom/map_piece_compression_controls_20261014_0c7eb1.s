.setcpu "65816"
.segment "CODE"
.org $7EB1
map_control_0c7eb1:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
