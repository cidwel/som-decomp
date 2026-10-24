.setcpu "65816"
.segment "CODE"
.org $F67E
map_control_0ef67e:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
