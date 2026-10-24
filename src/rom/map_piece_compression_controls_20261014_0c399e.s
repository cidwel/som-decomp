.setcpu "65816"
.segment "CODE"
.org $399E
map_control_0c399e:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
