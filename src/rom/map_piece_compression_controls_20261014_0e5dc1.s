.setcpu "65816"
.segment "CODE"
.org $5DC1
map_control_0e5dc1:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
