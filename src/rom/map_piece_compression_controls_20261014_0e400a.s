.setcpu "65816"
.segment "CODE"
.org $400A
map_control_0e400a:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
