.setcpu "65816"
.segment "CODE"
.org $81CB
map_control_0d81cb:
    .byte $E0 ; previous-row copy escape
    .byte $41 ; row-distance/count
