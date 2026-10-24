.setcpu "65816"
.segment "CODE"
.org $71E1
map_control_0c71e1:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
