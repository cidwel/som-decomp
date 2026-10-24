.setcpu "65816"
.segment "CODE"
.org $F417
map_control_0ff417:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
