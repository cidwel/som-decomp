.setcpu "65816"
.segment "CODE"
.org $890C
map_control_0f890c:
    .byte $E5 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
