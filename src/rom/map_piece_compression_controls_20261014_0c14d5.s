.setcpu "65816"
.segment "CODE"
.org $14D5
map_control_0c14d5:
    .byte $F2 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
