.setcpu "65816"
.segment "CODE"
.org $533E
map_control_0c533e:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
