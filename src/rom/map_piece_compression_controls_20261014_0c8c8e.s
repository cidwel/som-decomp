.setcpu "65816"
.segment "CODE"
.org $8C8E
map_control_0c8c8e:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
