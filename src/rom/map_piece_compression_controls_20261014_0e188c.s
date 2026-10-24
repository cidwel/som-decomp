.setcpu "65816"
.segment "CODE"
.org $188C
map_control_0e188c:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
