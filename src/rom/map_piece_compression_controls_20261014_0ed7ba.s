.setcpu "65816"
.segment "CODE"
.org $D7BA
map_control_0ed7ba:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
