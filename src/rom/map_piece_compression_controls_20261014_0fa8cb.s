.setcpu "65816"
.segment "CODE"
.org $A8CB
map_control_0fa8cb:
    .byte $E4 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
