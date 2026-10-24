.setcpu "65816"
.segment "CODE"
.org $791B
map_control_0d791b:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
