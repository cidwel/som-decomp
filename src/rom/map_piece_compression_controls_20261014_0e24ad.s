.setcpu "65816"
.segment "CODE"
.org $24AD
map_control_0e24ad:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
