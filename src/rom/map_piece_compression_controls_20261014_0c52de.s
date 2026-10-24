.setcpu "65816"
.segment "CODE"
.org $52DE
map_control_0c52de:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
