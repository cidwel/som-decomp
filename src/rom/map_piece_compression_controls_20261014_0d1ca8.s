.setcpu "65816"
.segment "CODE"
.org $1CA8
map_control_0d1ca8:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
