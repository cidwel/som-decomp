.setcpu "65816"
.segment "CODE"
.org $0DB1
map_control_0f0db1:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
