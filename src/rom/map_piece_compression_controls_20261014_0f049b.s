.setcpu "65816"
.segment "CODE"
.org $049B
map_control_0f049b:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
