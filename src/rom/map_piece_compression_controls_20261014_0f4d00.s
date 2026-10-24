.setcpu "65816"
.segment "CODE"
.org $4D00
map_control_0f4d00:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
