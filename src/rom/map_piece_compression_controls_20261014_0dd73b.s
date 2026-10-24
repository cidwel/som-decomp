.setcpu "65816"
.segment "CODE"
.org $D73B
map_control_0dd73b:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
