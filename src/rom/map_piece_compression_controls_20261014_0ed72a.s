.setcpu "65816"
.segment "CODE"
.org $D72A
map_control_0ed72a:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E4 ; previous-row copy count
