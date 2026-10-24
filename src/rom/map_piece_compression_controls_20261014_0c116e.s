.setcpu "65816"
.segment "CODE"
.org $116E
map_control_0c116e:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
