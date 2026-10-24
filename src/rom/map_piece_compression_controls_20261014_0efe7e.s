.setcpu "65816"
.segment "CODE"
.org $FE7E
map_control_0efe7e:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
