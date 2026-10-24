.setcpu "65816"
.segment "CODE"
.org $618A
map_control_0e618a:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
