.setcpu "65816"
.segment "CODE"
.org $BF4E
map_control_0ebf4e:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
