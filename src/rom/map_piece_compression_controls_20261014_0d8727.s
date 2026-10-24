.setcpu "65816"
.segment "CODE"
.org $8727
map_control_0d8727:
    .byte $E0 ; previous-row copy escape
    .byte $4B ; row-distance/count
