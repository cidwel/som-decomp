.setcpu "65816"
.segment "CODE"
.org $A390
map_control_0ea390:
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
