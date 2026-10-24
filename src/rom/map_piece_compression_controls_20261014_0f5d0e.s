.setcpu "65816"
.segment "CODE"
.org $5D0E
map_control_0f5d0e:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
