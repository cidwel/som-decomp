.setcpu "65816"
.segment "CODE"
.org $742B
map_control_0f742b:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
