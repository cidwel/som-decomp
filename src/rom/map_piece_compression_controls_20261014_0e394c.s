.setcpu "65816"
.segment "CODE"
.org $394C
map_control_0e394c:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
