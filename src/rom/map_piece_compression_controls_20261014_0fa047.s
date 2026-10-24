.setcpu "65816"
.segment "CODE"
.org $A047
map_control_0fa047:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
