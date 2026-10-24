.setcpu "65816"
.segment "CODE"
.org $AE9A
map_control_0fae9a:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
    .byte $E4 ; previous-row copy count
