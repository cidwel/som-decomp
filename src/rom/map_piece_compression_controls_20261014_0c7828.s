.setcpu "65816"
.segment "CODE"
.org $7828
map_control_0c7828:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
