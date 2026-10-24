.setcpu "65816"
.segment "CODE"
.org $2758
map_control_0c2758:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
