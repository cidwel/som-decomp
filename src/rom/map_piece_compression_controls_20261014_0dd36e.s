.setcpu "65816"
.segment "CODE"
.org $D36E
map_control_0dd36e:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
