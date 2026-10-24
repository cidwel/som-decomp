.setcpu "65816"
.segment "CODE"
.org $758D
map_control_0d758d:
    .byte $E0 ; previous-row copy escape
    .byte $CC ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $50 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $4C ; row-distance/count
