.setcpu "65816"
.segment "CODE"
.org $4ECA
map_control_0e4eca:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
