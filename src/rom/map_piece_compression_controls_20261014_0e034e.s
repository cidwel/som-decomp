.setcpu "65816"
.segment "CODE"
.org $034E
map_control_0e034e:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
