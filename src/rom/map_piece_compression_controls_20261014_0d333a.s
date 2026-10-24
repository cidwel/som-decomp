.setcpu "65816"
.segment "CODE"
.org $333A
map_control_0d333a:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
