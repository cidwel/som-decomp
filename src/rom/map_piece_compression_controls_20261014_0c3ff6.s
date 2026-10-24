.setcpu "65816"
.segment "CODE"
.org $3FF6
map_control_0c3ff6:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
