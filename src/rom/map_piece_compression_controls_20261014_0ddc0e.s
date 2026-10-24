.setcpu "65816"
.segment "CODE"
.org $DC0E
map_control_0ddc0e:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
