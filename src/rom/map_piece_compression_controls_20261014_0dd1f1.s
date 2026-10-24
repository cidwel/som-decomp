.setcpu "65816"
.segment "CODE"
.org $D1F1
map_control_0dd1f1:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
