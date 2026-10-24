.setcpu "65816"
.segment "CODE"
.org $829A
map_control_0d829a:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
