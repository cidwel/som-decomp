.setcpu "65816"
.segment "CODE"
.org $6EEC
map_control_0c6eec:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
