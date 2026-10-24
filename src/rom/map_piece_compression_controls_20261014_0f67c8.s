.setcpu "65816"
.segment "CODE"
.org $67C8
map_control_0f67c8:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
