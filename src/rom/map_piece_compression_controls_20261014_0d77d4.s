.setcpu "65816"
.segment "CODE"
.org $77D4
map_control_0d77d4:
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count
