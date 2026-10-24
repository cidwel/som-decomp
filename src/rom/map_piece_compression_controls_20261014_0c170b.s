.setcpu "65816"
.segment "CODE"
.org $170B
map_control_0c170b:
    .byte $F2 ; progressive-copy count
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
