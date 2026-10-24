.setcpu "65816"
.segment "CODE"
.org $510E
map_control_0f510e:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
