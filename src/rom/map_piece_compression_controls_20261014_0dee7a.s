.setcpu "65816"
.segment "CODE"
.org $EE7A
map_control_0dee7a:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $A1 ; row-distance/count
