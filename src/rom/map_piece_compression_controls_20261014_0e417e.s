.setcpu "65816"
.segment "CODE"
.org $417E
map_control_0e417e:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
