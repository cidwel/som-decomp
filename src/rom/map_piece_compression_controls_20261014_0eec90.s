.setcpu "65816"
.segment "CODE"
.org $EC90
map_control_0eec90:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
