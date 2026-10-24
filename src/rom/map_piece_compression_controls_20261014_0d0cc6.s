.setcpu "65816"
.segment "CODE"
.org $0CC6
map_control_0d0cc6:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A6 ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
