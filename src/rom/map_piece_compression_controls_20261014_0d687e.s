.setcpu "65816"
.segment "CODE"
.org $687E
map_control_0d687e:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
