.setcpu "65816"
.segment "CODE"
.org $485E
map_control_0c485e:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
