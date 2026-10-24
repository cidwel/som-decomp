.setcpu "65816"
.segment "CODE"
.org $C76B
map_control_0dc76b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
