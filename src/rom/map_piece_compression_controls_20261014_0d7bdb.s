.setcpu "65816"
.segment "CODE"
.org $7BDB
map_control_0d7bdb:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
