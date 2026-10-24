.setcpu "65816"
.segment "CODE"
.org $2981
map_control_0f2981:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
    .byte $E1 ; previous-row copy count
