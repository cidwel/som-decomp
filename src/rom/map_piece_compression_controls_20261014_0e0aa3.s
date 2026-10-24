.setcpu "65816"
.segment "CODE"
.org $0AA3
map_control_0e0aa3:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
