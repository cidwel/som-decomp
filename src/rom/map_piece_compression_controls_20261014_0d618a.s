.setcpu "65816"
.segment "CODE"
.org $618A
map_control_0d618a:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
