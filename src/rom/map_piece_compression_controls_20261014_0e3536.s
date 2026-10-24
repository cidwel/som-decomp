.setcpu "65816"
.segment "CODE"
.org $3536
map_control_0e3536:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
