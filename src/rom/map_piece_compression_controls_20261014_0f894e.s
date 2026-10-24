.setcpu "65816"
.segment "CODE"
.org $894E
map_control_0f894e:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
