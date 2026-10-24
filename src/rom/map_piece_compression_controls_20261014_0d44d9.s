.setcpu "65816"
.segment "CODE"
.org $44D9
map_control_0d44d9:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
