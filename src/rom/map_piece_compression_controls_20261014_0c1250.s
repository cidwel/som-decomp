.setcpu "65816"
.segment "CODE"
.org $1250
map_control_0c1250:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
