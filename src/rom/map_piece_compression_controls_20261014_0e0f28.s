.setcpu "65816"
.segment "CODE"
.org $0F28
map_control_0e0f28:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $1A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
