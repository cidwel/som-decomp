.setcpu "65816"
.segment "CODE"
.org $541C
map_control_0e541c:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
