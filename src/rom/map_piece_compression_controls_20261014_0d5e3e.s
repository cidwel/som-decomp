.setcpu "65816"
.segment "CODE"
.org $5E3E
map_control_0d5e3e:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
