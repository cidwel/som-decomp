.setcpu "65816"
.segment "CODE"
.org $2348
map_control_0c2348:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
