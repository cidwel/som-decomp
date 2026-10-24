.setcpu "65816"
.segment "CODE"
.org $29BB
map_control_0f29bb:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
