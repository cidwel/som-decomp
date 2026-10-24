.setcpu "65816"
.segment "CODE"
.org $35AA
map_control_0d35aa:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
