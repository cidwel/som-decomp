.setcpu "65816"
.segment "CODE"
.org $2885
map_control_0f2885:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $45 ; row-distance/count
