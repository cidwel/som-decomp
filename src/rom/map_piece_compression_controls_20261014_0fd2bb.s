.setcpu "65816"
.segment "CODE"
.org $D2BB
map_control_0fd2bb:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
