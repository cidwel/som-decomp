.setcpu "65816"
.segment "CODE"
.org $B71E
map_control_0eb71e:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
