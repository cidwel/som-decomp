.setcpu "65816"
.segment "CODE"
.org $273B
map_control_0e273b:
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
    .byte $E3 ; previous-row copy count
