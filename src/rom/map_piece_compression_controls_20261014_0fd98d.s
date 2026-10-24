.setcpu "65816"
.segment "CODE"
.org $D98D
map_control_0fd98d:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
