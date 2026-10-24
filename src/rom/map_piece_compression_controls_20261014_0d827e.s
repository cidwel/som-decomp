.setcpu "65816"
.segment "CODE"
.org $827E
map_control_0d827e:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
