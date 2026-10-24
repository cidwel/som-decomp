.setcpu "65816"
.segment "CODE"
.org $F23E
map_control_0ff23e:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
