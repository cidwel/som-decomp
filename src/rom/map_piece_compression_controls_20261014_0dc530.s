.setcpu "65816"
.segment "CODE"
.org $C530
map_control_0dc530:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
