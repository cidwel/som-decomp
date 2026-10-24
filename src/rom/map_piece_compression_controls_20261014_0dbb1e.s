.setcpu "65816"
.segment "CODE"
.org $BB1E
map_control_0dbb1e:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
