.setcpu "65816"
.segment "CODE"
.org $8796
map_control_0e8796:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
