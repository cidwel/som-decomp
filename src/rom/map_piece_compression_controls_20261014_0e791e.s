.setcpu "65816"
.segment "CODE"
.org $791E
map_control_0e791e:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
