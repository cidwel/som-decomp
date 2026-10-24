.setcpu "65816"
.segment "CODE"
.org $057E
map_control_0f057e:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
