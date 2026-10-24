.setcpu "65816"
.segment "CODE"
.org $EB60
map_control_0eeb60:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
