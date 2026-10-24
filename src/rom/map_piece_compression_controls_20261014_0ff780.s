.setcpu "65816"
.segment "CODE"
.org $F780
map_control_0ff780:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
