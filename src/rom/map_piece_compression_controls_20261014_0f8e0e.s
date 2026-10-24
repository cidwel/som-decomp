.setcpu "65816"
.segment "CODE"
.org $8E0E
map_control_0f8e0e:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
