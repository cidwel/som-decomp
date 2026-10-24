.setcpu "65816"
.segment "CODE"
.org $51D2
map_control_0f51d2:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
