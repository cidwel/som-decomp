.setcpu "65816"
.segment "CODE"
.org $F40A
map_control_0df40a:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
