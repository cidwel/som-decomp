.setcpu "65816"
.segment "CODE"
.org $D100
map_control_0ed100:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
