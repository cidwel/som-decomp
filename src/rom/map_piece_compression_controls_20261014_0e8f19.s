.setcpu "65816"
.segment "CODE"
.org $8F19
map_control_0e8f19:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
