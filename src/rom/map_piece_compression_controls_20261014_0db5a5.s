.setcpu "65816"
.segment "CODE"
.org $B5A5
map_control_0db5a5:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $4C ; distance low bit/count
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $5A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $46 ; row-distance/count
