.setcpu "65816"
.segment "CODE"
.org $1722
map_control_0f1722:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
