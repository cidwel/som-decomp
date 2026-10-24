.setcpu "65816"
.segment "CODE"
.org $8CA1
map_control_0d8ca1:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
