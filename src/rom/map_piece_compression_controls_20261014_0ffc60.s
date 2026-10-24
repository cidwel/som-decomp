.setcpu "65816"
.segment "CODE"
.org $FC60
map_control_0ffc60:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
