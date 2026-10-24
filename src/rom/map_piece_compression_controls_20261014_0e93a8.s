.setcpu "65816"
.segment "CODE"
.org $93A8
map_control_0e93a8:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
