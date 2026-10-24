.setcpu "65816"
.segment "CODE"
.org $CF1E
map_control_0fcf1e:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
