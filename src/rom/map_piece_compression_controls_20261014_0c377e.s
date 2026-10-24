.setcpu "65816"
.segment "CODE"
.org $377E
map_control_0c377e:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
