.setcpu "65816"
.segment "CODE"
.org $CFD7
map_control_0dcfd7:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
