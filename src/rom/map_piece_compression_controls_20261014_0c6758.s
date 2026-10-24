.setcpu "65816"
.segment "CODE"
.org $6758
map_control_0c6758:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
