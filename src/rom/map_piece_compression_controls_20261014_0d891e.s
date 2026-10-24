.setcpu "65816"
.segment "CODE"
.org $891E
map_control_0d891e:
    .byte $E0 ; previous-row copy escape
    .byte $AD ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $54 ; row-distance/count
