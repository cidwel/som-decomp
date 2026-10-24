.setcpu "65816"
.segment "CODE"
.org $38B3
map_control_0f38b3:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
