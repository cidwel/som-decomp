.setcpu "65816"
.segment "CODE"
.org $0AC4
map_control_0d0ac4:
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $B3 ; row-distance/count
