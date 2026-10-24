.setcpu "65816"
.segment "CODE"
.org $AC71
map_control_0fac71:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
