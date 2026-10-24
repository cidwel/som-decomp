.setcpu "65816"
.segment "CODE"
.org $F73E
map_control_0df73e:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
