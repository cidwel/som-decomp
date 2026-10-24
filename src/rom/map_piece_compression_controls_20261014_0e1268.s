.setcpu "65816"
.segment "CODE"
.org $1268
map_control_0e1268:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
