.setcpu "65816"
.segment "CODE"
.org $AE0E
map_control_0eae0e:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
