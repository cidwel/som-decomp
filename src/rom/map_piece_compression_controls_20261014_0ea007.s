.setcpu "65816"
.segment "CODE"
.org $A007
map_control_0ea007:
    .byte $E3 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
