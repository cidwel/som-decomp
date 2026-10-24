.setcpu "65816"
.segment "CODE"
.org $AA6A
map_control_0eaa6a:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
