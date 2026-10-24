.setcpu "65816"
.segment "CODE"
.org $6224
map_control_0d6224:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
