.setcpu "65816"
.segment "CODE"
.org $3E71
map_control_0e3e71:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
