.setcpu "65816"
.segment "CODE"
.org $5D75
map_control_0e5d75:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
