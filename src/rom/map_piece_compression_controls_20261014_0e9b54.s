.setcpu "65816"
.segment "CODE"
.org $9B54
map_control_0e9b54:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A9 ; row-distance/count
