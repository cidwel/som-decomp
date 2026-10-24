.setcpu "65816"
.segment "CODE"
.org $73A2
map_control_0d73a2:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
