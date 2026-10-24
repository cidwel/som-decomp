.setcpu "65816"
.segment "CODE"
.org $2057
map_control_0e2057:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
