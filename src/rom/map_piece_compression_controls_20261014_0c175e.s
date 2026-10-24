.setcpu "65816"
.segment "CODE"
.org $175E
map_control_0c175e:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
