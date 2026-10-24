.setcpu "65816"
.segment "CODE"
.org $9FA3
map_control_0d9fa3:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
