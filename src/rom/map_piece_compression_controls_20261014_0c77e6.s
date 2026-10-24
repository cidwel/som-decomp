.setcpu "65816"
.segment "CODE"
.org $77E6
map_control_0c77e6:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
