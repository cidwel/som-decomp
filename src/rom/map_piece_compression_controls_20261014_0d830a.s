.setcpu "65816"
.segment "CODE"
.org $830A
map_control_0d830a:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
