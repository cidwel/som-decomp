.setcpu "65816"
.segment "CODE"
.org $CBD2
map_control_0ecbd2:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
