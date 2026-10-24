.setcpu "65816"
.segment "CODE"
.org $1644
map_control_0c1644:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
