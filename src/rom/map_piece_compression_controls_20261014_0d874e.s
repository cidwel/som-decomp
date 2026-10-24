.setcpu "65816"
.segment "CODE"
.org $874E
map_control_0d874e:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
