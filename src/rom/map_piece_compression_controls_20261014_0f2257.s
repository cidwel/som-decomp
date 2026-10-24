.setcpu "65816"
.segment "CODE"
.org $2257
map_control_0f2257:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $3E ; distance low bit/count
