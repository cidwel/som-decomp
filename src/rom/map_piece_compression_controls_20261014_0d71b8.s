.setcpu "65816"
.segment "CODE"
.org $71B8
map_control_0d71b8:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
