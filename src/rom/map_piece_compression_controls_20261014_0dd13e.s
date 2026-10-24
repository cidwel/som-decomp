.setcpu "65816"
.segment "CODE"
.org $D13E
map_control_0dd13e:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
