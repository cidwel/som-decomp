.setcpu "65816"
.segment "CODE"
.org $51F8
map_control_0e51f8:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
