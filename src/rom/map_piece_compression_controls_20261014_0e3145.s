.setcpu "65816"
.segment "CODE"
.org $3145
map_control_0e3145:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
