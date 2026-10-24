.setcpu "65816"
.segment "CODE"
.org $F32E
map_control_0df32e:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
