.setcpu "65816"
.segment "CODE"
.org $DF06
map_control_0edf06:
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
