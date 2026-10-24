.setcpu "65816"
.segment "CODE"
.org $116E
map_control_0e116e:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
