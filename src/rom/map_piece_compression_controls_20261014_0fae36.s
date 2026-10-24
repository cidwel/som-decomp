.setcpu "65816"
.segment "CODE"
.org $AE36
map_control_0fae36:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A2 ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $5C ; row-distance/count
