.setcpu "65816"
.segment "CODE"
.org $F2CF
map_control_0ef2cf:
    .byte $E0 ; previous-row copy escape
    .byte $AF ; row-distance/count
