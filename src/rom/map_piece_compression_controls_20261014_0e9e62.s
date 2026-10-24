.setcpu "65816"
.segment "CODE"
.org $9E62
map_control_0e9e62:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
