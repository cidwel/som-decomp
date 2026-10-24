.setcpu "65816"
.segment "CODE"
.org $2F9E
map_control_0c2f9e:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
