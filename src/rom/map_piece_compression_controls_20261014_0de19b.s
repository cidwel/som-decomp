.setcpu "65816"
.segment "CODE"
.org $E19B
map_control_0de19b:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
