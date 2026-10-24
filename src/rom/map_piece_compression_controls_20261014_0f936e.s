.setcpu "65816"
.segment "CODE"
.org $936E
map_control_0f936e:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
