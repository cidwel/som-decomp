.setcpu "65816"
.segment "CODE"
.org $4D2B
map_control_0f4d2b:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $43 ; row-distance/count
