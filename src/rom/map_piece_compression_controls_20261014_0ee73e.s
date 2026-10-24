.setcpu "65816"
.segment "CODE"
.org $E73E
map_control_0ee73e:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
