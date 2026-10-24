.setcpu "65816"
.segment "CODE"
.org $54A2
map_control_0d54a2:
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
