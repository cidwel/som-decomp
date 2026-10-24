.setcpu "65816"
.segment "CODE"
.org $F510
map_control_0df510:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
