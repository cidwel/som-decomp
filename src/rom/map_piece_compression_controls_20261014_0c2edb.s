.setcpu "65816"
.segment "CODE"
.org $2EDB
map_control_0c2edb:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
