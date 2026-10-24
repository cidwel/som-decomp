.setcpu "65816"
.segment "CODE"
.org $B53E
map_control_0db53e:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
