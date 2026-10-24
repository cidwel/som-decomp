.setcpu "65816"
.segment "CODE"
.org $140E
map_control_0e140e:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
