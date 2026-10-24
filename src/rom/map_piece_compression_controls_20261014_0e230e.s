.setcpu "65816"
.segment "CODE"
.org $230E
map_control_0e230e:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
