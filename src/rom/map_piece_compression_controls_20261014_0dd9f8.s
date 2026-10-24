.setcpu "65816"
.segment "CODE"
.org $D9F8
map_control_0dd9f8:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
