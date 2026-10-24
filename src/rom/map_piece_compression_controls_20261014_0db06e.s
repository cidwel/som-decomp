.setcpu "65816"
.segment "CODE"
.org $B06E
map_control_0db06e:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
