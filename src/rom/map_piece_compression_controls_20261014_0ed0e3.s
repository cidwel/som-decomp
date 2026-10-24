.setcpu "65816"
.segment "CODE"
.org $D0E3
map_control_0ed0e3:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
