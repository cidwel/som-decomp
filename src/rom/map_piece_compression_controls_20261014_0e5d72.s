.setcpu "65816"
.segment "CODE"
.org $5D72
map_control_0e5d72:
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
