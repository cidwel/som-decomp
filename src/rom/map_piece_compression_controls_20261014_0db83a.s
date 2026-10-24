.setcpu "65816"
.segment "CODE"
.org $B83A
map_control_0db83a:
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
