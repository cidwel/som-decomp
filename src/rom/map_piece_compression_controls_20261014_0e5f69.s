.setcpu "65816"
.segment "CODE"
.org $5F69
map_control_0e5f69:
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
