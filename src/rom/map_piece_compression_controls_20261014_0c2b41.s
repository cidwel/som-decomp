.setcpu "65816"
.segment "CODE"
.org $2B41
map_control_0c2b41:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $71 ; row-distance/count
