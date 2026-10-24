.setcpu "65816"
.segment "CODE"
.org $BBD8
map_control_0fbbd8:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $2A ; distance low bit/count
    .byte $E2 ; previous-row copy count
