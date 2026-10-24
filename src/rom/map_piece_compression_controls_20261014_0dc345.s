.setcpu "65816"
.segment "CODE"
.org $C345
map_control_0dc345:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
