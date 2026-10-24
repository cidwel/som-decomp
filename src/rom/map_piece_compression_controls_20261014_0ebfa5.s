.setcpu "65816"
.segment "CODE"
.org $BFA5
map_control_0ebfa5:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
