.setcpu "65816"
.segment "CODE"
.org $321E
map_control_0c321e:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
