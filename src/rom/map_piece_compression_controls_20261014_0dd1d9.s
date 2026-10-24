.setcpu "65816"
.segment "CODE"
.org $D1D9
map_control_0dd1d9:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
