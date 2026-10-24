.setcpu "65816"
.segment "CODE"
.org $0718
map_control_0f0718:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
