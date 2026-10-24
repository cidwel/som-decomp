.setcpu "65816"
.segment "CODE"
.org $CFC2
map_control_0fcfc2:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
