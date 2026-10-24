.setcpu "65816"
.segment "CODE"
.org $F405
map_control_0ef405:
    .byte $E0 ; previous-row copy escape
    .byte $3D ; row-distance/count
