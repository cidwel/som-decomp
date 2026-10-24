.setcpu "65816"
.segment "CODE"
.org $A0F7
map_control_0ea0f7:
    .byte $EE ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E4 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $4E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $6E ; distance low bit/count
