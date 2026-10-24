.setcpu "65816"
.segment "CODE"
.org $DC5E
map_control_0ddc5e:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
