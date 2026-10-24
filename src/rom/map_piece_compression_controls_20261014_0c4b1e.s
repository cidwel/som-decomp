.setcpu "65816"
.segment "CODE"
.org $4B1E
map_control_0c4b1e:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
