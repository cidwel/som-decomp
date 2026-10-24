.setcpu "65816"
.segment "CODE"
.org $A022
map_control_0da022:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
