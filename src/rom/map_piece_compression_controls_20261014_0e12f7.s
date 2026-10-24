.setcpu "65816"
.segment "CODE"
.org $12F7
map_control_0e12f7:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
