.setcpu "65816"
.segment "CODE"
.org $9948
map_control_0f9948:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
