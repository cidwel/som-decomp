.setcpu "65816"
.segment "CODE"
.org $CCD8
map_control_0fccd8:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
