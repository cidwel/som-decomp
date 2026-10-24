.setcpu "65816"
.segment "CODE"
.org $A545
map_control_0ea545:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E3 ; previous-row copy count
