.setcpu "65816"
.segment "CODE"
.org $8CA8
map_control_0c8ca8:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
