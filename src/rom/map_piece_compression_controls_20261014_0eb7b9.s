.setcpu "65816"
.segment "CODE"
.org $B7B9
map_control_0eb7b9:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $4C ; row-distance/count
