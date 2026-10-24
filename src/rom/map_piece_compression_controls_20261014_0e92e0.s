.setcpu "65816"
.segment "CODE"
.org $92E0
map_control_0e92e0:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
