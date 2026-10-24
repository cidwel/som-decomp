.setcpu "65816"
.segment "CODE"
.org $2FBD
map_control_0e2fbd:
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
