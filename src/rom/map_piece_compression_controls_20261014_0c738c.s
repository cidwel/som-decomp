.setcpu "65816"
.segment "CODE"
.org $738C
map_control_0c738c:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
