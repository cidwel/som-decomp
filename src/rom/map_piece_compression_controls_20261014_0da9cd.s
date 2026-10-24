.setcpu "65816"
.segment "CODE"
.org $A9CD
map_control_0da9cd:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E1 ; previous-row copy count
