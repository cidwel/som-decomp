.setcpu "65816"
.segment "CODE"
.org $D491
map_control_0ed491:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
