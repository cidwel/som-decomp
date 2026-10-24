.setcpu "65816"
.segment "CODE"
.org $D603
map_control_0dd603:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
