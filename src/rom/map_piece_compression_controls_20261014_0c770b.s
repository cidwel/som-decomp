.setcpu "65816"
.segment "CODE"
.org $770B
map_control_0c770b:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
