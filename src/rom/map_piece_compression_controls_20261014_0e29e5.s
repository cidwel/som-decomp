.setcpu "65816"
.segment "CODE"
.org $29E5
map_control_0e29e5:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
