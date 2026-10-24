.setcpu "65816"
.segment "CODE"
.org $7D75
map_control_0e7d75:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
