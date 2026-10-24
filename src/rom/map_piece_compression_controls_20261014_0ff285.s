.setcpu "65816"
.segment "CODE"
.org $F285
map_control_0ff285:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
