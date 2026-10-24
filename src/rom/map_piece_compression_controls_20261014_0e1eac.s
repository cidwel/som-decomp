.setcpu "65816"
.segment "CODE"
.org $1EAC
map_control_0e1eac:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E1 ; previous-row copy count
