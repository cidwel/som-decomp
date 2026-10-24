.setcpu "65816"
.segment "CODE"
.org $285E
map_control_0e285e:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
