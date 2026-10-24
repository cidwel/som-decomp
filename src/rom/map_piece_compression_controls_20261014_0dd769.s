.setcpu "65816"
.segment "CODE"
.org $D769
map_control_0dd769:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
