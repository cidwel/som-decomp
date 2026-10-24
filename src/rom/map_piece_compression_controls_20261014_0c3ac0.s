.setcpu "65816"
.segment "CODE"
.org $3AC0
map_control_0c3ac0:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
