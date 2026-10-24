.setcpu "65816"
.segment "CODE"
.org $A52C
map_control_0fa52c:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
