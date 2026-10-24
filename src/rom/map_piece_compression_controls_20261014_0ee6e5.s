.setcpu "65816"
.segment "CODE"
.org $E6E5
map_control_0ee6e5:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
