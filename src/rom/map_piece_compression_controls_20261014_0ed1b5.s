.setcpu "65816"
.segment "CODE"
.org $D1B5
map_control_0ed1b5:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
