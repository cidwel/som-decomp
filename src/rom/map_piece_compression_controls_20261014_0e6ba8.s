.setcpu "65816"
.segment "CODE"
.org $6BA8
map_control_0e6ba8:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
