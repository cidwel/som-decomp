.setcpu "65816"
.segment "CODE"
.org $6204
map_control_0d6204:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
