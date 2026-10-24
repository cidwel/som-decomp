.setcpu "65816"
.segment "CODE"
.org $889E
map_control_0f889e:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
