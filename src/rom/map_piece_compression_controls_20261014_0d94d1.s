.setcpu "65816"
.segment "CODE"
.org $94D1
map_control_0d94d1:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
