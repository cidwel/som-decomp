.setcpu "65816"
.segment "CODE"
.org $768A
map_control_0f768a:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
