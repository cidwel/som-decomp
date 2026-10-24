.setcpu "65816"
.segment "CODE"
.org $59A5
map_control_0d59a5:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7C ; row-distance/count
