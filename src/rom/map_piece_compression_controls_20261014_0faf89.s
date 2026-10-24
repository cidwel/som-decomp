.setcpu "65816"
.segment "CODE"
.org $AF89
map_control_0faf89:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $C6 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E4 ; previous-row copy count
