.setcpu "65816"
.segment "CODE"
.org $DF4F
map_control_0edf4f:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
