.setcpu "65816"
.segment "CODE"
.org $400A
map_control_0f400a:
    .byte $E0 ; previous-row copy escape
    .byte $44 ; row-distance/count
