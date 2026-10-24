.setcpu "65816"
.segment "CODE"
.org $362A
map_control_0d362a:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
