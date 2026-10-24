.setcpu "65816"
.segment "CODE"
.org $679E
map_control_0c679e:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
