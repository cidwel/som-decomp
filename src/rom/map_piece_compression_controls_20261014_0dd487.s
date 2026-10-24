.setcpu "65816"
.segment "CODE"
.org $D487
map_control_0dd487:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
