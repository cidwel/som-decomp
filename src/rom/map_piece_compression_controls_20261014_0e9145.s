.setcpu "65816"
.segment "CODE"
.org $9145
map_control_0e9145:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
