.setcpu "65816"
.segment "CODE"
.org $8879
map_control_0e8879:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
    .byte $E3 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A7 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A3 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $F3 ; row-distance/count
