.setcpu "65816"
.segment "CODE"
.org $728A
map_control_0c728a:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
