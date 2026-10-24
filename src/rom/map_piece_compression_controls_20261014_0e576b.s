.setcpu "65816"
.segment "CODE"
.org $576B
map_control_0e576b:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E3 ; previous-row copy count
