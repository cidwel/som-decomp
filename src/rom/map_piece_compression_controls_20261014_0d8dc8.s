.setcpu "65816"
.segment "CODE"
.org $8DC8
map_control_0d8dc8:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
