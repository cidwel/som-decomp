.setcpu "65816"
.segment "CODE"
.org $3141
map_control_0e3141:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
