.setcpu "65816"
.segment "CODE"
.org $F51A
map_control_0ff51a:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
