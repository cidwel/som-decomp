.setcpu "65816"
.segment "CODE"
.org $2141
map_control_0f2141:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
